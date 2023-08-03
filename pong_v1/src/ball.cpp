#include <SDL2/SDL.h>

class Ball {
public:
    float x, y, dx, dy;
    Ball(float x, float y);
    void move();
    void render(SDL_Renderer* renderer);
};

Ball::Ball(float x, float y) : x(x), y(y), dx(1), dy(1) {}

void Ball::move() {
    x += dx;
    y += dy;

    // Boundary checks
    if (x <= 0 || x >= 630) dx = -dx;
    if (y <= 0 || y >= 470) dy = -dy;
}

void Ball::render(SDL_Renderer* renderer) {
    SDL_Rect rect = { x, y, 10, 10 };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}

