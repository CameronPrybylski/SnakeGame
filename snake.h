#ifndef _SNAKE_H_
#define _SNAKE_H_

#include "entity.h"
#include "SDL.h"
#include <vector>
#include <queue>
#include <string>

class Snake : Entity{

public:

    Snake(SDL_Renderer* ren);
    ~Snake();

    void update(int changeX, int changeY, bool add);
    void addToBody();
    void render();
    std::vector<SDL_Rect> getBody();
    bool hitWall(int width, int height);
    bool hitBody();

private:

    std::vector<SDL_Rect> body;
    std::string direction;

};

#endif