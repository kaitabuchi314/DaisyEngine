#pragma once
#include "libs/sdl2/SDL.h"
#include "libs/sdl2/SDL_image.h" // Cannont find libs/SDL.h??

namespace Daisy {
    class Renderer
    {
    public:
        Renderer(int width, int height, bool resizable, int fps);
        ~Renderer();
        void Render_Image(Image image, int x, int y, int x_scale, int y_scale);
        void Render_Rect(int x, int y, int x_scale, int y_scale, Color color);
        void end_frame();
    private:
        SDL_Window* window;
        SDL_Renderer* renderer;
        int fps;
    };

    class Color // Repersents an RGBA color
    {
    public:
        float r;
        float g;
        float b;
        float a;
        Color(float r, float g, float b, float a)
         {
            this->r = r;
            this->g = g;
            this->b = b;
            this->a = a;
        }
    };

    class Image // Repersents an image
    {
    public:
        SDL_Surface* surface;
        
        Image(const char* path) { surface = SDL_LoadBMP(path); }
    };

    class Input_System
    {
    public:
        void Poll_Events();
        bool K_SPACE_DOWN;
        bool WINDOW_CLOSED;
    };


    Image Load_Image(const char* path);
}
