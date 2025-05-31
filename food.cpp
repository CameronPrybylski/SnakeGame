#include "food.h"
#include <cstdlib>
#include <ctime>

Food::Food(int screenWidth, int screenHeight, int width, int height, SDL_Renderer* ren) : Entity(ren){
    this->screenWidth = screenWidth;
    this->screenHeight = screenHeight;
    this->width = width;
    this->height = height;
    this->location.h = height;
    this->location.w = width;
    update();
}

void Food::update(){
    int min = width;
    int maxWidth = screenWidth - 10;
    int maxHeight = screenHeight - 10;
    int randX = (std::rand() % (maxWidth - min + 1)) + min;
    int randY = (std::rand() % (maxHeight - min + 1)) + min;
    this->location.x = randX;
    this->location.y = randY;
}

void Food::render(){
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    SDL_RenderFillRect(renderer, &location);
}

SDL_Rect Food::getLocation(){
    return this->location;
}