#include "game.h"
#include <iostream>


Game::Game(){}

Game::~Game(){}


void Game::init(const char* title, int xpos, int ypos, int width, int height){
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0){
        std::cout << "Subsystems Initialized" << std::endl;

        window = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
        renderer = SDL_CreateRenderer(window, -1, 0);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        this->isRunning = true;
        snake = new Snake(renderer);
        food = new Food(width, height, 10, 10, renderer);
        this->screenHeight = height;
        this->screenWidth = width;
    }
    else{
        this->isRunning = false;
    }
    
}

void Game::handleEvents(){
    SDL_Event event;
    SDL_PollEvent(&event);
    switch (event.type)
    {
        case SDL_QUIT:
            isRunning = false;
            break;
        case SDL_KEYDOWN:
            handleKeyboardEvent(event, true);
            break;
        default:
            break;
    }
    if(foodEaten()){
        isFoodEaten = true;
    }
    if(hitWall()){
        hasHitWall = true;
    }
    if(snake->hitBody()){
        hasHitBody = true;
    }
}

void Game::handleKeyboardEvent(SDL_Event event, bool keyPressed){
    SDL_Keycode key = event.key.keysym.sym;
    
    if(key == SDLK_w && direction != "Down"){
        direction = "Up";
    }
    if(key == SDLK_s && direction != "Up"){
        direction = "Down";
    }
    if(key == SDLK_a && direction != "Right"){
        direction = "Left";
    }
    if(key == SDLK_d && direction != "Left"){
        direction = "Right";
    }
    
}

bool Game::foodEaten(){
    SDL_Rect foodLocation = food->getLocation();
    SDL_Rect snakeLocation = snake->getBody()[0];
    return (foodLocation.x <= snakeLocation.x + snakeLocation.w && foodLocation.x + foodLocation.w >= snakeLocation.x) 
    && (foodLocation.y <= snakeLocation.y + snakeLocation.h && foodLocation.y + foodLocation.h >= snakeLocation.y);
}

bool Game::hitWall(){
   return snake->hitWall(screenWidth, screenHeight);
}

void Game::update(){
    int changeX = 0;
    int changeY = 0;
    if(direction == "Down"){
        changeY += 10;
    }
    if(direction == "Up"){
       changeY -= 10;
    }
    if(direction == "Left"){
       changeX -= 10;
    }
    if(direction == "Right"){
        changeX += 10;
    }
    snake->update(changeX, changeY, isFoodEaten);
    if(isFoodEaten){
        food->update();
        isFoodEaten = false;
    }
    if(hasHitWall || hasHitBody){
        isRunning = false;
    }
}

void Game::render(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    snake->render();
    food->render();

    SDL_RenderPresent(renderer);
}

void Game::clean(){
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
}

bool Game::running(){
    return this->isRunning;
}