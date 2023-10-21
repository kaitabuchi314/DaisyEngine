#include "Daisy.h"

namespace Daisy {
    Renderer::Renderer(int width, int height, bool resizable, int fps)
    {
        SDL_Init(SDL_INIT_VIDEO); // Init SDL
        this->fps = fps; // This is the target FPS
        if (resizable)
        {
            window = SDL_CreateWindow("Daisy Renderer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_RESIZABLE);
        }
        else
        {
            window = SDL_CreateWindow("Daisy Renderer", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height);
        }
        renderer = SDL_CreateRenderer(window, -1, 0);
    }
    Renderer::~Renderer() // Quit SDL on destruction of renderer
    {
        SDL_Quit();
    }
    void Renderer::Render_Image(Image image, int x, int y, int x_scale, int y_scale)
    {
        SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, image.surface); // Create a texture from the image's surface
        SDL_Rect dest_rect; // Create a rect to position and scale the image.
        dest_rect.x = x;
        dest_rect.y = y;
        dest_rect.w = x_scale;
        dest_rect.h = y_scale;
        SDL_RenderCopy(renderer, texture, NULL, &dest_rect); // Render the image
        SDL_DestroyTexture(texture); // Destroy the texture
    }

    void Renderer::Render_Rect(int x, int y, int x_scale, int y_scale, Color color)
    {
        SDL_Rect rect; // Create a rect based of the function perameters
        rect.x = x;
        rect.y = y;
        rect.w = x_scale;
        rect.h = y_scale;
        SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a); // Set the color to draw with.
        SDL_RenderFillRect(renderer, &rect);
    }

    void Renderer::end_frame()
    {
        SDL_Delay(1000 / this->fps); // Every frame, wait for a small time based on the FPS.
    }
    void Input_System::Poll_Events()
    {
        SDL_Event event; 
        while (SDL_PollEvent(&event)) // See what events happen
        {
            if (event.type == SDL_KEYDOWN) 
            {
                if (event.key.keysym.sym == SDLK_SPACE) // IF the space key is down, set a variable to true;
                {
                    K_SPACE_DOWN = true; // TODO: Make a system to easily update lots of variables.
                }
            }
            else if (event.type == SDL_WINDOWEVENT_CLOSE) // Some other events like window closing;
            {
                WINDOW_CLOSED = true;
            }
            else
            {
                K_SPACE_DOWN = false; // If no events, then reset all of them.
                WINDOW_CLOSED = false;
            }
        }
    }

    Image Load_Image(const char* p) // Load an image, return an Image
    {
        Image img(p);
        return img;
    }
}
