#include <SDL2/SDL.h>

class Paddle {
public:
    float x, y, dy;
    Paddle(float x, float y);
    void move();
    void render(SDL_Renderer* renderer);
};

Paddle::Paddle(float x, float y) : x(x), y(y), dy(0) {}

void Paddle::move() {
    y += dy;
    // Add boundary checks
    if (y < 0) y = 0;
    if (y > 420) y = 420; 
}

void Paddle::render(SDL_Renderer* renderer) {
    SDL_Rect rect = { x, y, 10, 60 };
    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    SDL_RenderFillRect(renderer, &rect);
}