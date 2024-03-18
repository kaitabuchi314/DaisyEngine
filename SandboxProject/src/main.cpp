#include <Daisy.h>

namespace SandboxLayer
{
    class SandboxLayer : public Daisy::Layer
    {
    public:
        SandboxLayer() : window(1000, 800, "My Window") {};

        void Init() override;

        void Run() override;

        void Quit() override;

    public:
        Daisy::Window window;
        Daisy::Renderer2D renderer;
        Daisy::Image img;
    };

    void SandboxLayer::Init()
    {
        id = 0;

        renderer.InitRenderer();

        Daisy::ActivateRenderer(&renderer);
        img = Daisy::LoadImage("guy.png");
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
    }
}

int main()
{
    SandboxLayer::SandboxLayer* layer = new SandboxLayer::SandboxLayer();
    Daisy::LayerManager::PushLayer(layer);
    Daisy::LayerManager::activeLayer = layer->id;

    Daisy::LayerManager::Run();

    delete layer;
    return 0;
}