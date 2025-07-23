#include "GamePanel.h"

GamePanel::GamePanel(wxFrame* parent)
    : wxPanel(parent, wxID_ANY)
{
    SetBackgroundStyle(wxBG_STYLE_PAINT);

    Bind(wxEVT_KEY_DOWN, &GamePanel::OnKeyDown, this);
    Bind(wxEVT_TIMER, &GamePanel::OnTimer, this);
    Bind(wxEVT_PAINT, &GamePanel::OnPaint, this);

    m_dotPos = wxPoint(20, 20);
    m_keyStatus = "Press any key";

    m_timer = new wxTimer(this, 1);
    m_timer->Start(1000); // 1초마다 OnTimer 호출
}

GamePanel::~GamePanel()
{
    m_timer->Stop();
    delete m_timer;
}

// 키보드 이벤트: 눌린 키 정보를 m_keyStatus에 저장하고 화면 갱신
void GamePanel::OnKeyDown(wxKeyEvent& event)
{
    m_keyStatus = wxString::Format("Key Pressed: %c", (char)event.GetKeyCode());
    Refresh();
}

// 타이머 이벤트: 점의 x좌표를 5씩 이동시키고 화면 갱신
void GamePanel::OnTimer(wxTimerEvent& event)
{
    m_dotPos.x += 5;
    Refresh();
}

// 그리기 이벤트: 점과 키보드 상태 텍스트를 화면에 그림
void GamePanel::OnPaint(wxPaintEvent& event)
{
    wxPaintDC dc(this);
    dc.DrawPoint(m_dotPos);
    dc.DrawText(m_keyStatus, wxPoint(20, 50));
}
