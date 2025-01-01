#include "window.h"

namespace VanK
{
    Window::Window(Application& app) : m_App(app)
    {
        std::cout << "new Window Class" << std::endl;
        initWindow();
    }

    Window::~Window()
    {
        std::cout << "delete Window" << std::endl;
        SDL_DestroyWindow(window);
    }

    void Window::initWindow()
    {
        if (!SDL_Init(SDL_INIT_VIDEO)) {
            SDL_Log("Couldn't initialize SDL: %s", SDL_GetError());
        }

        window = SDL_CreateWindow("examples/renderer/clear", 640, 480, SDL_WINDOW_RESIZABLE);
        if (!window) {
            SDL_Log("Couldn't create window: %s", SDL_GetError());
        }
    }
}