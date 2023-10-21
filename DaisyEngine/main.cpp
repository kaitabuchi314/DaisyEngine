#include "Daisy.h"

int main()
{
    int WINDOW_WIDTH = 800; // The width of the window
    int WINDOW_HEIGHT = 600; // The height of the window
    int FPS = 80; // Set the target FPS to 80
    bool resizable = true; // Make the window resizable
    Daisy::Renderer daisy_renderer(WINDOW_WIDTH, WINDOW_HEIGHT, resizable, FPS); // Create a renderer using my Daisy Game Engine

    Daisy::Image image = Daisy::Load_Image("img.jpg"); // Load an image using my Daisy Game Engine
    Daisy::Color red(1.0f, 0.0f, 0.0f, 1.0f); // Red: 1.0, Green: 0.0, Blue: 0.0, Alpha: 1.0
    Daisy::Color blue(0.0f, 0.0f, 1.0f, 1.0f); // Red: 0.0, Green: 0.0, Blue: 1.0, Alpha: 1.0
    Daisy::Input_System input_system;
    /*
        This simple input system used is temporary and will be rewritten.
        The code will still work with the new input system, but input will also have defineable actions,
        not just keys down and mouses down.
    */
    
    bool app_running = true;
    while (app_running) // While the app is still running.
    {
        input_system.Poll_Events(); // Update the events
        if (input_system.WINDOW_CLOSED) // If the window closes, make sure to stop the app from running
        {
            app_running = false;
        }
        daisy_renderer.Render_Image(image, 0, 0, 60, 60); // Render an image
        if (input_system.K_SPACE_DOWN) { // Depending on if the space key is pressed, render a red or blue rectangle.
            daisy_renderer.Render_Rect(90, 30, 60, 60, red);
        }
        else {
            daisy_renderer.Render_Rect(90, 30, 60, 60, blue);
        }
        daisy_renderer.end_frame(); // End the frame.
    }
    return 0;
}