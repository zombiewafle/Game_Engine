#pragma once

#include <SDL2/SDL.h>


class Ball {
public:
    float x, y, dx, dy;
    Ball(float x, float y);
    void move();
    void render(SDL_Renderer* renderer); // Add this line
};
