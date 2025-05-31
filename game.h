#ifndef _GAME_H_
#define _GAME_H_

#include "SDL.h"
#include "snake.h"
#include "food.h"
#include <string>

class Game{

public:

    Game();
    ~Game();

    void init(const char* title, int xpos, int ypos, int width, int height);

    void handleEvents();
    void update();
    void render();
    void clean();
    bool running();

    void handleKeyboardEvent(SDL_Event event, bool keyPressed);
    bool foodEaten();
    bool hitWall();

private:
    bool isRunning;
    SDL_Window *window;
    SDL_Renderer *renderer;
    Snake* snake;
    Food* food;
    bool isFoodEaten;
    bool hasHitWall;
    bool hasHitBody;
    int screenWidth;
    int screenHeight;
    std::string direction;

};


#endif

