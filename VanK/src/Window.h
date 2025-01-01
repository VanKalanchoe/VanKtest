#pragma once
#include "core.h"

namespace VanK
{
    //forward declare
    class Application;
    
    class Window
    {
    public:
        Window(Application& app);
        ~Window();
        
        void initWindow();
        SDL_Window* getWindow() const { return window; }
    private:
        SDL_Window* window = nullptr;
        Application& m_App; // Store the reference to Application
    };
}
