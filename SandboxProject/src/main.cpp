#include <iostream>
#include <Window.h>
#include <Renderer2D.h>


int main()
{
    Daisy::Window window(1000, 800, "My Window");

    Daisy::Renderer2D renderer;
    renderer.InitOpenGL();

    renderer.GenShaders();
    renderer.GenBuffers();

    Daisy::Image img = renderer.LoadImage("guy.png");
    Daisy::Image img2 = renderer.LoadImage("kitten.png");

    float x = 0;
    float y = 0;

    float x2 = 0;
    float y2 = 0;

    while (!window.WindowClosed())
    {
        x = x + 0.0001f;
        y = y + 0.0001f;
        x2 = x2 + -0.0001f;
        y2 = y2 + -0.0001f;
        
        renderer.ClearScreen(0.3f, 0.6f, 0.2f);

        renderer.DrawImage(img, x, y, 0.2f, 0.2f);
        renderer.DrawImage(img2, x2, y2, 0.5f, 0.5f);

        window.EndFrame();
    }

    
    Daisy::FlushImage(img);
    renderer.Flush();
    window.Flush();
    return 0;
}