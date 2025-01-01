#include <iostream>
#include <ostream>

#include "VanK.h"

/*
class ExampleLayer : public VanK::Layer
{
    public:
    ExampleLayer() : Layer("Example")
    {
      
    }

    void OnUpdate() override
    {
        //std::cout << "Example Layer::OnUpdate" << std::endl;
    }

    void OnEvent(VanK::Event& event) override
    {
        std::cout << "Example Layer::OnEvent" << std::endl;

        if (event.GetName() == std::string("KeyEvent")) {
            auto& keyEvent = dynamic_cast<VanK::KeyEvent&>(event);

            if (keyEvent.GetType() == VanK::KeyEvent::Type::KeyPressed && keyEvent.GetKey() == SDL_SCANCODE_W) {
                std::cout << "W key pressed in ExampleLayer!" << std::endl;
            }

            event.SetHandled(true);  // Mark the event as handled
        }
    }
};*/

class SandBox final : public VanK::Application
{
public:
    SandBox()
    {
        std::cout << "SandBox::SandBox()" << '\n';
        //PushLayer(new ExampleLayer());
    }

    ~SandBox() override
    {
        std::cout << "SandBox::~SandBox()" << '\n';
    }

    /*// Override the OnMouseMoved method to handle mouse movement events
    void OnMouseMoved(const VanK::MouseMovedEvent& event) override
    {
        std::cout << "Mouse moved in Sandbox to: (" << event.GetX() << ", " << event.GetY() << ")" << std::endl;
    }*/
};

VanK::Application* VanK::CreateApplication()
{
    return new SandBox();
}
