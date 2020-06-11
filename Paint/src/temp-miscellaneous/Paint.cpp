#include <iostream>
#include "SDL.h"

int main(int argc, char* args[])
{

    // initialize SDL and check for init success
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    SDL_Window *window = SDL_CreateWindow("Canvas", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1920, 1080, SDL_WINDOW_OPENGL);

    // window initialization fails
    if (window == nullptr)
    {
        std::cout << "Window failed to initialize: " << SDL_GetError << std::endl;
        SDL_Quit();

        return 1;
    }

    // create and test for successful renderer creation
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer == nullptr) {
        SDL_DestroyWindow(window);
        std::cout << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // load bitmap and check creation
    SDL_Surface *bmp = SDL_LoadBMP("D:\\DOWNLOADS\\wolf.bmp");
    if (bmp == nullptr) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        std::cout << "SDL_LoadBMP Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }

    // create a texture for rendering from surface
    SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, bmp);
    //We no longer need the surface
    SDL_FreeSurface(bmp);
    if (texture == nullptr) {
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        std::cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        return 1;
    }


    // main program logic
    for (int i = 0; i < 5; ++i) {
        //First clear the renderer
        SDL_RenderClear(renderer);
        //Draw the texture
        SDL_RenderCopy(renderer, texture, NULL, NULL);
        //Update the screen
        SDL_RenderPresent(renderer);
        //Take a quick break after all that hard work
        SDL_Delay(1000);
    };

    // cleanup and close
    SDL_DestroyTexture(texture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();


    return 0;

}