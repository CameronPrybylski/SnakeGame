#include "game.h"
#include <iostream>

int main() {
    
    //SDL_Init(SDL_INIT_VIDEO);
    Game *game = new Game();
    game->init("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600);

    int FPS = 60;
    int frameDelay = 1000 / FPS;

    Uint32 frameStart;
    int frameTime;

    while(game->running()){

        frameStart = SDL_GetTicks();

        game->handleEvents();
        game->update();
        game->render();

        frameTime = SDL_GetTicks() - frameStart;

        if(frameDelay > frameTime){
            SDL_Delay((frameDelay - frameTime) * 3);
        }
        
    }
    game->clean();

    
    return 0;
}
