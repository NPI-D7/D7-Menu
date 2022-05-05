#include "common.hpp"
#include "splash.hpp"
#include "TitleManager.hpp"

int main()
{ 
    RenderD7::Init::Main("D7-Menu");
    RenderD7::Msg::void Display("D7-Menu", "Scanning SD", Top);
    TitleManager::ScanSD();
    RenderD7::Scene::Load(std::make_unique<Stack>());
    while (RenderD7::MainLoop())
    {

        RenderD7::FrameEnd();
    }
    RenderD7::Exit::Main();
    return 0;
}
