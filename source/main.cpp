#include "common.hpp"
#include "splash.hpp"
#include "TitleManager.hpp"

int main()
{ 
    RenderD7::Init::Main("D7-Menu");
    mkdir("sdmc:/D7-Menu", 0777);
    mkdir("sdmc:/D7-Menu/cache", 0777);
    RenderD7::Msg::Display("D7-Menu", "Scanning SD", Top);
    TitleManager::ScanSD("sdmc:/D7-Menu/");
    TitleManager::ScanCard();
    RenderD7::Scene::Load(std::make_unique<Stack>());
    while (RenderD7::MainLoop())
    {

        RenderD7::FrameEnd();
    }
    RenderD7::Exit::Main();
    return 0;
}
