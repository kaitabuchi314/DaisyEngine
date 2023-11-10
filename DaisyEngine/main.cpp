#pragma once


#include "Daisy.h"
#include "EditorLayer.h"

int main(int argc, char* argv[])
{
    const int WINDOW_WIDTH = 800; // The width of the window
    const int WINDOW_HEIGHT = 600; // The height of the window
    const char* WINDOW_NAME = "DaisyEngine Window";
    int FPS = 80; // Set the target FPS to 80
    bool resizable = true; // Make the window resizable
    if (SDL_Init(SDL_INIT_VIDEO) < 0) return 1;
    SDL_Window* window;

    if (resizable)
    {
        window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_RESIZABLE);
    }
    else
    {
        window = SDL_CreateWindow(WINDOW_NAME, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    }

    if (!window)
    {
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    IMG_Init(IMG_INIT_PNG);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048);
    SDL_Surface* imageSurface = IMG_Load("image.png");
    SDL_Texture* imageTexture = SDL_CreateTextureFromSurface(renderer, imageSurface);
    SDL_Rect imageRect;
    imageRect.x = WINDOW_HEIGHT / 2;
    imageRect.y = WINDOW_HEIGHT / 2;
    imageRect.w = 100;
    imageRect.h = 100;
    SDL_FreeSurface(imageSurface);

    Daisy::EditorLayer editorlayer(renderer, window);
    editorlayer.Start();
    SDL_Event e;
    bool quit = false;
    while (!quit)
    {
        while (SDL_PollEvent(&e) != 0)
        {
            editorlayer.EventPolled(e);
            if (e.type == SDL_QUIT)
            {
                quit = true;
            }
        }

        int w, h;

        SDL_GetRendererOutputSize(renderer, &w, &h);

        imageRect.x = editorlayer.pos.x;
        imageRect.y = editorlayer.pos.y;
        imageRect.w = editorlayer.scale.x;
        imageRect.h = editorlayer.scale.y;
        editorlayer.Preloop();

        editorlayer.Loop();
        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, imageTexture, NULL, &imageRect);
        editorlayer.Draw();
        SDL_RenderPresent(renderer);
        SDL_Delay(1000 / FPS); // Every frame, wait for a small time based on the FPS.
    }

    SDL_DestroyTexture(imageTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    IMG_Quit();
    SDL_Quit();

    return 0;
}
