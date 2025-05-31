#include "snake.h"
#include <iostream>

Snake::Snake(SDL_Renderer* ren) : Entity(ren) {
    for(int i = 0; i < 5; i++){
        SDL_Rect head;
        head.x = 100 - (i * 10);   // Top-left x coordinate
        head.y = 100;   // Top-left y coordinate
        head.w = 10;   // Width of the head
        head.h = 10;   // Height of the head
        body.push_back(head);
    }

}

Snake::~Snake(){}

void Snake::addToBody(){
    SDL_Rect bodyPart;
    bodyPart.x = body[body.size() - 1].x;   // Top-left x coordinate
    bodyPart.y = body[body.size() - 1].y;   // Top-left y coordinate
    bodyPart.w = 10;   // Width of the bodyPart
    bodyPart.h = 10;   // Height of the head
    body.push_back(bodyPart);

}

void Snake::update(int changeX, int changeY, bool add){
    if(changeX != 0 || changeY != 0){
        if(add){
            addToBody();
        }
        for(int i = body.size() - 1; i > 0; i--){
            
            body[i].x = body[i-1].x;
            body[i].y = body[i-1].y;
            
        }
        body[0].x += changeX;
        body[0].y += changeY;
    }
}

void Snake::render(){
    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);
    for(int i = 0; i < body.size(); i++){
        SDL_RenderFillRect(renderer, &body[i]);
    }
}

std::vector<SDL_Rect> Snake::getBody(){
    return this->body;
}

bool Snake::hitWall(int width, int height){
    if(body[0].y <= 0 || body[0].x <= 0 || body[0].y + 10 >= height || body[0].x + 10 >= width){
        return true;
    }else{
        return false;
    }
}

bool Snake::hitBody(){
    for(int i = 1; i < body.size(); i++){
        if((body[0].x <= body[i].x + body[i].w - 1 && body[0].x + body[0].w - 1 >= body[i].x) 
            && (body[0].y <= body[i].y + body[i].h - 1 && body[0].y + body[0].h - 1 >= body[i].y)){
                return true;
            }
    }
    return false;
}