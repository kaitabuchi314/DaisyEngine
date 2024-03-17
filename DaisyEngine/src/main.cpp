#include <include/GL/glew.h>
#include <glfw3.h>
#include <stb_image.h>
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

    float x = 0;
    float y = 0;

    while (!window.WindowClosed())
    {

        x = x + 1;
        y = y + 1;

        renderer.ClearScreen(0.3f, 0.6f, 0.2f);

        renderer.DrawImage(img, x, y);

        window.EndFrame();
    }

    
    Daisy::FlushImage(img);
    renderer.Flush();
    window.Flush();
    return 0;
}