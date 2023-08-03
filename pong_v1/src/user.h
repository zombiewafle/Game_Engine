#pragma once
#include <SDL2/SDL.h>


class Paddle {
public:
    float x, y, dy;
    Paddle(float x, float y);
    void move();
    void render(SDL_Renderer* renderer);
};
