#include "GameFrame.h"
#include "GamePanel.h"

GameFrame::GameFrame()
    : wxFrame(NULL, wxID_ANY, "Minimal Template", wxDefaultPosition, wxSize(300, 200))
{
    // 프레임 안에 GamePanel을 생성합니다.
    GamePanel* panel = new GamePanel(this);
    // 패널에 포커스를 줍니다.
    panel->SetFocus();
}
