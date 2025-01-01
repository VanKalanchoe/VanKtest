#pragma once
#include "core.h"

namespace VanK
{
    class Window;
    class Renderer;
    
    class Application
    {
    public:
        Application();
        virtual ~Application();
    };
    
    inline Application* app;
    inline std::unique_ptr<Window> window = nullptr;
    inline std::unique_ptr<Renderer> renderer = nullptr;
    // To be defined in CLIENT
    Application* CreateApplication();
}
