#include <Daisy.h>

namespace SandboxLayer
{
    class AppleScript : public Daisy::Script
    {
    public:
        virtual void onStart(Daisy::GameObject* self) override
        {
            std::cout << "apple";
        }
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
    };

    void SandboxLayer::Init()
    {
        id = 0;

        renderer.InitRenderer();

        Daisy::ActivateRenderer(&renderer);
        img = Daisy::LoadImage("guy.png");

        Daisy::Scripts::scripts["Apple"] = CreateAppleScript;
        sc = new Daisy::ScriptComponent();
        sc->scriptName = "Apple";
        object = Daisy::GameObject();
        object.addComponent(sc);
        //object.components.push_back(sc);
        
        object.onStart();
        
    }

    void SandboxLayer::Run()
    {
        while (!window.WindowClosed())
        {
            renderer.ClearScreen(0.3f, 0.6f, 0.2f);

            Daisy::DrawImage(img, 0, 0, 0.2f, 0.2f);

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