#pragma once
#include "core.h"

namespace VanK
{
    class Shader;
    class Texture;
    
    class Renderer
    {
    public:
        Renderer(Window& window);
        ~Renderer();
        static void drawQuadTexture(SDL_Surface* imageData);
        int init();
        int Draw();

    private:
        Window& m_Window;
    };
}
