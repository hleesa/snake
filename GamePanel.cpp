#include "GamePanel.h"
#include "Config.h"
#include "Apple.h"

GamePanel::GamePanel(wxFrame* parent)
        : wxPanel(parent, wxID_ANY) {
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_KEY_DOWN, &GamePanel::OnKeyDown, this);
    Bind(wxEVT_TIMER, &GamePanel::OnTimer, this);
    Bind(wxEVT_PAINT, &GamePanel::OnPaint, this);

    board.initWall();
    board.setCell(snake.getHead(), CellType::SNAKE);
    apple.init(board.getCells());
    for (auto p: apple.getPositions()) {
        board.setCell(p, CellType::APPLE);
    }

    m_timer = new wxTimer(this, 1);
    m_timer->Start(100); // 1초마다 OnTimer 호출
}

GamePanel::~GamePanel()
{
    m_timer->Stop();
    delete m_timer;
}

// 키보드 이벤트:
void GamePanel::OnKeyDown(wxKeyEvent& event)
{
    switch (event.GetKeyCode()) {
        case WXK_UP:
            snake.setDirection(Direction::UP);
            break;
        case WXK_DOWN:
            snake.setDirection(Direction::DOWN);
            break;
        case WXK_LEFT:
            snake.setDirection(Direction::LEFT);
            break;
        case WXK_RIGHT:
            snake.setDirection(Direction::RIGHT);
            break;
        case WXK_ESCAPE:
            GetParent()->Close(true);
        default:
            break;
    }
    m_keyStatus = wxString::Format("Key Pressed: %c", (char)event.GetKeyCode());
    Refresh();
}

// 타이머 이벤트:
void GamePanel::OnTimer(wxTimerEvent& event)
{
    int beforeSnakeTail = snake.getTail();
    int newSnakeHead = snake.move(board.getCells());

    if (newSnakeHead == -1) {
        return;
    }

    CellType type = board.getType(newSnakeHead);
    if (type == CellType::APPLE) {
        board.setCell(apple.create(board.getCells()), CellType::APPLE);
        apple.erase(newSnakeHead);
    }
    board.setCell(newSnakeHead, CellType::SNAKE);
    board.setCell(beforeSnakeTail, CellType::EMPTY);
    Refresh();
}

// 그리기 이벤트: 점과 키보드 상태 텍스트를 화면에 그림
void GamePanel::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    for(int y = 0; y < BOARD_HEIGHT; ++y){
        for(int x = 0; x < BOARD_WIDTH; ++x){
            switch (board.getCells()[y * BOARD_WIDTH + x]) {
                case CellType::SNAKE:
                    dc.SetBrush(*wxRED_BRUSH);
                    dc.SetPen(*wxTRANSPARENT_PEN);
                    dc.DrawRectangle(x * CELL_WIDTH, y * CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT);
                    break;
                case CellType::WALL:
                    dc.SetBrush(*wxBLUE_BRUSH);
                    dc.SetPen(*wxTRANSPARENT_PEN);
                    dc.DrawRectangle(x * CELL_WIDTH, y * CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT);
                    break;
                case CellType::APPLE:
                    dc.SetBrush(*wxGREEN_BRUSH);
                    dc.SetPen(*wxTRANSPARENT_PEN);
                    dc.DrawRectangle(x * CELL_WIDTH, y * CELL_HEIGHT, CELL_WIDTH, CELL_HEIGHT);
                    break;
                case CellType::EMPTY:
                    break;
            }
        }
    }
}
