#include "GameFrame.h"
#include "GamePanel.h"
#include "Config.h"

GameFrame::GameFrame()
        : wxFrame(NULL, wxID_ANY, "Snake") {

    SetClientSize(FRAME_WIDTH, FRAME_HEIGHT);
    // 프레임 안에 GamePanel을 생성합니다.
    GamePanel* panel = new GamePanel(this);
    // 패널에 포커스를 줍니다.
    panel->SetFocus();

    Center();
}
