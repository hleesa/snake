#ifndef SNAKE_GAME_GAMEPANEL_H
#define SNAKE_GAME_GAMEPANEL_H

#include <wx/wx.h>
#include <vector>
#include "CellType.h"
#include "GameBoard.h"
#include "Snake.h"
#include "Apple.h"

class GamePanel : public wxPanel
{
public:
    GamePanel(wxFrame* parent);
    ~GamePanel();

private:
    void OnKeyDown(wxKeyEvent& event);
    void OnTimer(wxTimerEvent& event);
    void OnPaint(wxPaintEvent& event);


    GameBoard board;
    Apple apple;
    Snake snake;

    wxTimer* m_timer;
    wxString m_keyStatus;  // 키보드 입력 상태를 표시할 문자열
};

#endif //SNAKE_GAME_GAMEPANEL_H
