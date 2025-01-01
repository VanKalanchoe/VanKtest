#pragma once
#include "core.h"

namespace VanK
{
    class Shader;
    class Texture;
    
    class Renderer
    {
    public:
        Renderer(Application& app, Window& window);
        ~Renderer();

        void initRenderer();
        void BeginScene();
        void EndScene();
        void clearColor();
        void setColor(float r, float g, float b, float a);
        void Bind() const;
        void drawQuadTexture(SDL_Surface* imageData);
        void lol();
        void Drawss();
        void drawQuad();
        void createPipeline();

        SDL_GPUGraphicsPipeline* getPipeline() const { return Pipeline; };
        SDL_GPUDevice* getDevice() const { return device; };
        SDL_GPUCommandBuffer* getGPUCommandBuffer() const { return cmdbuf; };
        
    private:
        Application& m_App; // Store the reference to Application
        Window& m_Window;
        SDL_GPUDevice* device = nullptr;
        SDL_GPUGraphicsPipeline* Pipeline = nullptr;
        SDL_GPUCommandBuffer* cmdbuf = nullptr;
        SDL_GPUTexture* swapchainTexture = nullptr;
        SDL_GPUColorTargetInfo colorTargetInfo;
        SDL_GPURenderPass* renderPass = nullptr;
        SDL_GPUBuffer* VertexBuffer = nullptr;
        SDL_GPUBuffer* IndexBuffer = nullptr;
        SDL_GPUTexture* Texture = nullptr;
        SDL_GPUSampler* Sampler = nullptr;
        bool hasCreateQuad = false;
    };
  
 

    typedef struct PositionTextureVertex
    {
        float x, y, z;
        float u, v;
    } PositionTextureVertex;
}
