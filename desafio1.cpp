#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h> // Mantenha esta linha
#include <iostream>

int main(int argc, char* args[]) {
    SDL_Init(SDL_INIT_VIDEO);

    SDL_Window *window = SDL_CreateWindow(
        "desafio 1",
        800,
        600,
        0
    );
    bool quit = false;
    SDL_Event e;

    while(!quit){
        if (SDL_PollEvent(&e) != 0){
            if(e.type == SDL_EVENT_QUIT){
                quit = true;
            }
            if(e.type == SDL_EVENT_KEY_DOWN){
                if(e.key.key == SDLK_ESCAPE){
                    quit = true;
                }
            }
        }
    }

    return 0;
}