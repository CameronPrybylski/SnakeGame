#ifndef _FOOD_H_
#define _FOOD_H_

#include "SDL.h"
#include "entity.h"

class Food : Entity {

public:

    Food(int screenWidth, int screenHeight, int width, int height, SDL_Renderer* ren);
    ~Food();

    void update();
    void render();
    SDL_Rect getLocation();

private:

    SDL_Rect location;
    int width;
    int height;
    int screenWidth;
    int screenHeight;


};

#endif