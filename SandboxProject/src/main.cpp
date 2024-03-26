#include <Daisy.h>
#include <random>

namespace SandboxLayer
{
    class AppleScript : public Daisy::Script
    {
    public:
        virtual void onStart(Daisy::GameObject* self) override
        {
            std::cout << "apple\n";
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
        object.addComponent(sc);
        //object.components.push_back(sc);
        
        object.onStart();
        
    }

    void SandboxLayer::Run()
    {

        while (!window.WindowClosed())
        {
            renderer.ClearScreen(0.3f, 0.6f, 0.2f);
            
            for (int i = 0; i < 1500; i++)
            {
                Daisy::DrawImage(img, Daisy::Random::RandomFloat(-500.0f,500.0f), Daisy::Random::RandomFloat(-400.0f, 400.0f), 0.03f, 0.03f);
            }

            double currentTime = glfwGetTime();
            nbFrames++;
            if (currentTime - lastTime >= 1.0)
            {
                printf("%f ms/frame\n", 1000.0 / double(nbFrames));
                nbFrames = 0;
                lastTime += 1.0;
            }
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