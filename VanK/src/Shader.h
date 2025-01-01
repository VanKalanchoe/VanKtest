#pragma once
#include "core.h"

namespace VanK
{
    class Shader
    {
    public:
        static SDL_GPUShader* LoadShader(
        SDL_GPUDevice* device,
        const char* shaderFilename,
        Uint32 samplerCount,
        Uint32 uniformBufferCount,
        Uint32 storageBufferCount,
        Uint32 storageTextureCount);
    };
}
