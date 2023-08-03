#include <SDL2/SDL.h>
#include "user.h"
#include "ball.h"

const int FPS_SAMPLES = 10;
int frameTimesIndex = 0;
int frameTimes[FPS_SAMPLES];
int lastFrameTime = 0;
float fps = 0;

int main(int argc, char *argv[]) {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Pong", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 640, 480, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    Paddle leftPaddle(50, 240), rightPaddle(590, 240);
    Ball ball(320, 240);

    bool running = true;
    SDL_Event event;

    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
        }

        // Handle user input
        const Uint8* state = SDL_GetKeyboardState(NULL);
        rightPaddle.dy = state[SDL_SCANCODE_UP] ? -1 : state[SDL_SCANCODE_DOWN] ? 1 : 0;
        leftPaddle.dy = state[SDL_SCANCODE_W] ? -1 : state[SDL_SCANCODE_S] ? 1 : 0;

        leftPaddle.move();
        rightPaddle.move();
        ball.move();

        // Collision detection
        if ((ball.x < leftPaddle.x + 10 && ball.y > leftPaddle.y && ball.y < leftPaddle.y + 60) ||
            (ball.x > rightPaddle.x - 10 && ball.y > rightPaddle.y && ball.y < rightPaddle.y + 60)) {
            ball.dx = -ball.dx;
        }

        // Render
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        
        leftPaddle.render(renderer);
        rightPaddle.render(renderer);
        ball.render(renderer);

        SDL_RenderPresent(renderer);

        // FPS Calculation
        int currentTime = SDL_GetTicks();
        int frameTime = currentTime - lastFrameTime;
        lastFrameTime = currentTime;

        frameTimes[frameTimesIndex % FPS_SAMPLES] = frameTime;
        frameTimesIndex++;

        int count = frameTimesIndex < FPS_SAMPLES ? frameTimesIndex : FPS_SAMPLES;
        float averageFrameTime = 0;
        for (int i = 0; i < count; i++) {
            averageFrameTime += frameTimes[i];
        }
        averageFrameTime /= count;

        fps = (averageFrameTime > 0) ? 1000.0f / averageFrameTime : 60.0f;
        
        static int lastFPSPrint = 0;
        if (currentTime - lastFPSPrint > 1000) {
            printf("FPS: %.2f\n", fps);
            lastFPSPrint = currentTime;
        }

        SDL_Delay(3);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
