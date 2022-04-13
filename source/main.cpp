#include "common.hpp"

int main()
{ 
    RenderD7::Init::Main("D7-Menu");
    RenderD7::Scene::Load(std::make_unique<Stack>());
    while (RenderD7::MainLoop())
    {

        RenderD7::FrameEnd();
    }
    RenderD7::Exit::Main();
    return 0;
}
