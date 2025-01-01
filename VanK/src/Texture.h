#pragma once

#include "core.h"

namespace VanK
{
    class Texture
    {
    public:
        static SDL_Surface* LoadImage(const char* imageFilename, int desiredChannels);
    };  
}