#include <Daisy.h>

int main()
{
    Daisy::Window window(1000, 800, "My Window");

    Daisy::Renderer2D renderer;

    renderer.InitRenderer();

    Daisy::Image img = renderer.LoadImage("guy.png");

    while (!window.WindowClosed())
    {
        renderer.ClearScreen(0.3f, 0.6f, 0.2f);

        renderer.DrawImage(img, 0, 0, 0.2f, 0.2f);

        window.EndFrame();
    }

    
    Daisy::FlushImage(img);
    renderer.Flush();
    window.Flush();
    return 0;
}