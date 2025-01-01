#define SDL_MAIN_USE_CALLBACKS
#include "Application.h"
#include <SDL3/SDL_main.h>

namespace VanK
{
    Application::Application()
    {
        std::cout << "Application::Application()" << '\n';
        // Initialize resources, create window, etc.
        window = std::make_unique<Window>(*this);
        renderer = std::make_unique<Renderer>(*this, *window);
    }

    Application::~Application()
    {
        std::cout << "Application::~Application()" << '\n';
      
        // Cleanup resources, close window, etc.
    }

    extern "C" {
    SDL_AppResult SDL_AppInit(void** appstate, int argc, char** argv)
    {
        SDL_SetAppMetadata("Engine Test", "1.0", "com.example.engine");

        *appstate = CreateApplication();

        app = static_cast<Application*>(*appstate);

        return SDL_APP_CONTINUE;
    }

    SDL_AppResult SDL_AppEvent(void* appstate, SDL_Event* event)
    {
        if (event->type == SDL_EVENT_QUIT)
        {
            return SDL_APP_SUCCESS; /* end the program, reporting success to the OS. */
        }
        if (event->type == SDL_EVENT_KEY_DOWN)
        {
            if (event->key.scancode == SDL_SCANCODE_ESCAPE)
            {
                return SDL_APP_SUCCESS;
            }
        }
        return SDL_APP_CONTINUE;
    }

    SDL_AppResult SDL_AppIterate(void* appstate)
    {
        renderer->Drawss();

        return SDL_APP_CONTINUE;
    }

    void SDL_AppQuit(void* appstate, SDL_AppResult result)
    {
        // Reset renderer and window explicitly before Application is fully destroyed
        if (renderer) {
            renderer.reset(); // Ensure renderer is destroyed
        }

        if (window) {
            window.reset(); // Ensure window is destroyed
        }
        delete app;
    }
    }
}
