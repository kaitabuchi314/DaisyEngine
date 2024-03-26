// This is a personal academic project. Dear PVS-Studio, please check it.
// PVS-Studio Static Code Analyzer for C, C++, C#, and Java: https://pvs-studio.com

#include <Daisy.h>
#include <random>

namespace SandboxLayer
{
    class AppleScript : public Daisy::Script
    {
    public:
        virtual void onStart(Daisy::GameObject* self) override
        {
            image = Daisy::LoadImage("guy.png");
        }

        virtual void onUpdate(Daisy::GameObject* self) override
        {
            if (Daisy::Input::GetKeyPressed(DAISY_KEY_RIGHT))
            {
                self->position.x += 0.001f;
            }
            else if (Daisy::Input::GetKeyPressed(DAISY_KEY_LEFT))
            {
                self->position.x -= 0.001f;
            }

            if (Daisy::Input::GetKeyPressed(DAISY_KEY_UP))
            {
                self->position.y += 0.001f;
            }
            else if (Daisy::Input::GetKeyPressed(DAISY_KEY_DOWN))
            {
                self->position.y -= 0.001f;
            }
        }

        virtual void onRender(Daisy::GameObject* self) override
        {
            Daisy::DrawImage(image, self->position.x, self->position.y, self->scale.x, self->scale.y);
        }
    private:
        Daisy::Image image;
    };

    Daisy::Script* CreateAppleScript()
    {
        return new AppleScript();
    }
    class SandboxLayer : public Daisy::Layer
    {
    public:
        SandboxLayer() : window(1000, 800, "My Window") {};

        void Init() override;

        void Run() override;

        void Quit() override;

    public:
        Daisy::GameObject object;
        Daisy::Window window;
        Daisy::Renderer2D renderer;
        Daisy::Image img;
        Daisy::ScriptComponent* sc;
        double lastTime;
        int nbFrames = 0;
    };

    void SandboxLayer::Init()
    {
        lastTime = glfwGetTime();
        id = 0;

        renderer.InitRenderer();

        Daisy::ActivateRenderer(&renderer);
        img = Daisy::LoadImage("guy.png");

        Daisy::Scripts::scripts["Apple"] = CreateAppleScript;
        sc = new Daisy::ScriptComponent();
        sc->scriptName = "Apple";
        object = Daisy::GameObject();
        object.scale.x = 0.3f;
        object.scale.y = 0.3f;

        object.addComponent(sc);
        //object.components.push_back(sc);
        
        object.onStart();
        
    }

    void SandboxLayer::Run()
    {

        while (!window.WindowClosed())
        {
            // Game Loop
            object.onUpdate();

            // Calculate ms/f
            double currentTime = glfwGetTime();
            nbFrames++;
            if (currentTime - lastTime >= 1.0)
            {
                printf("%f ms/frame\n", 1000.0 / double(nbFrames));
                nbFrames = 0;
                lastTime += 1.0;
            }

            // Render
            renderer.ClearScreen(0.3f, 0.6f, 0.2f);
            
            object.onRender();

            window.EndFrame();
        }
    }

    void SandboxLayer::Quit()
    {
        Daisy::FlushImage(img);
        renderer.Flush();
        window.Flush();
        delete sc;
    }
}

int main()
{
    SandboxLayer::SandboxLayer* layer = new SandboxLayer::SandboxLayer();
    Daisy::LayerManager::PushLayer(layer);
    Daisy::LayerManager::activeLayer = layer;

    Daisy::LayerManager::Run();

    delete layer;
    return 0;
}