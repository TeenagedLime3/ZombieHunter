#define SDL_MAIN_HANDLED
#include <iostream>
#include <SDL.h>

#include "Player.h"
#define UPDATE_INTERVAL 0.1f

typedef struct {
    SDL_Renderer *renderer;
    SDL_Window *window;
} Game;

int main(){
    Game game;
    if(SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        std::cout << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_DisplayMode dm;

    if (SDL_GetDesktopDisplayMode(0, &dm) != 0) {
        SDL_Log("SDL_GetDesktopDisplayMode failed: %s", SDL_GetError());
        return 1;
    }

    const int WINDOW_WIDTH = dm.w/2;
    const int WINDOW_HEIGHT = dm.h/2;

    const int originX = WINDOW_WIDTH / 2;
    const int originY = WINDOW_HEIGHT; //at the bottom so no /2

    game.window = SDL_CreateWindow("Zombie Hunter", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    game.renderer = SDL_CreateRenderer(game.window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

    Player* player = new Player();


    SDL_Event event;

    bool running = true;
    Uint32 lastFrameTime = SDL_GetTicks();
    float accumulatedTime = 0.0f;

    while(running) {
        Uint32 currentFrameTime = SDL_GetTicks();

        accumulatedTime += (currentFrameTime - lastFrameTime) / 1000.0f; // in seconds

        lastFrameTime = currentFrameTime;

        // input
        while(SDL_PollEvent(&event)) {
            if(event.type == SDL_QUIT) {
                running = false;
            }
            if(event.type == SDL_KEYDOWN) {
                player->handleInput(event.key.keysym.sym);
            }
        }

        //update
        while(accumulatedTime > UPDATE_INTERVAL) {
            accumulatedTime -= UPDATE_INTERVAL;
        }

        //render
        //background
        SDL_SetRenderDrawColor(game.renderer, 15, 236, 241, 255);
        SDL_RenderClear(game.renderer);

        //player
        player->render(game.renderer, originX, originY);

        //grass
        SDL_SetRenderDrawColor(game.renderer, 96, 180 , 74, 255);
        SDL_RenderFillRect(game.renderer, new SDL_Rect(0, originY - 100, WINDOW_WIDTH, originY));

        SDL_RenderPresent(game.renderer); //updates the screen
    }
}