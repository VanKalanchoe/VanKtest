#include "Texture.h"

namespace VanK
{
    SDL_Surface* Texture::LoadImage(const char* imageFilename, int desiredChannels)
    {
        char fullPath[256];
        SDL_Surface* result;
        SDL_PixelFormat format;

        SDL_snprintf(fullPath, sizeof(fullPath), "%sContent/Images/%s", SDL_GetBasePath(), imageFilename);

        result = IMG_Load(fullPath);
        if (result == nullptr)
        {
            SDL_Log("Failed to load Image: %s", SDL_GetError());
            return nullptr;
        }
        SDL_FlipSurface(result, SDL_FLIP_VERTICAL);
        if (desiredChannels == 4)
        {
            format = SDL_PIXELFORMAT_ABGR8888;
        }
        else
        {
            SDL_assert(!"Unexpected desiredChannels");
            SDL_DestroySurface(result);
            return nullptr;
        }
        if (result->format != format)
        {
            SDL_Surface* next = SDL_ConvertSurface(result, format);
            SDL_DestroySurface(result);
            result = next;
        }

        return result;
    }
}
