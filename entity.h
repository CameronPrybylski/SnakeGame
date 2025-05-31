#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "SDL.h"

class Entity{

public:

    Entity(SDL_Renderer* ren) : renderer(ren) {}
    ~Entity() {}

    void updateEntity();

protected:
    SDL_Renderer* renderer;

};


#endif