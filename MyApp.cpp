#include "MyApp.h"
#include "GameFrame.h"

IMPLEMENT_APP(MyApp)

bool MyApp::OnInit()
{
    GameFrame *frame = new GameFrame();
    frame->Show(true);
    return true;
}
