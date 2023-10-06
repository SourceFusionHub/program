#include <iostream>
#include <vector>
#include <SDL.h>

const int SCREEN_WIDTH = 800;
const int SCREEN_HEIGHT = 600;
const int NUM_DRONES = 10;
const int DRONE_SIZE = 20;

struct Drone {
    float x, y;
    float vx, vy;

    Drone(float x, float y) : x(x), y(y), vx(0), vy(0) {}
};

void updateDrones(std::vector<Drone>& drones) {
    // Update the position of drones (simplified behavior)
    for (auto& drone : drones) {
        drone.vx = (rand() % 3 - 1) * 2.0; // Random movement
        drone.vy = (rand() % 3 - 1) * 2.0;
        drone.x += drone.vx;
        drone.y += drone.vy;

        // Wrap around the screen
        if (drone.x < 0) drone.x = SCREEN_WIDTH;
        if (drone.x > SCREEN_WIDTH) drone.x = 0;
        if (drone.y < 0) drone.y = SCREEN_HEIGHT;
        if (drone.y > SCREEN_HEIGHT) drone.y = 0;
    }
}

void renderDrones(SDL_Renderer* renderer, const std::vector<Drone>& drones) {
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255); // Red color
    for (const auto& drone : drones) {
        SDL_Rect rect = {static_cast<int>(drone.x), static_cast<int>(drone.y), DRONE_SIZE, DRONE_SIZE};
        SDL_RenderFillRect(renderer, &rect);
    }
}

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        std::cerr << "SDL could not initialize! SDL_Error: " << SDL_GetError() << std::endl;
        return -1;
    }

    SDL_Window* window = SDL_CreateWindow("Drone Swarm Simulation", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

    std::vector<Drone> drones;
    for (int i = 0; i < NUM_DRONES; ++i) {
        drones.emplace_back(static_cast<float>(rand() % SCREEN_WIDTH), static_cast<float>(rand() % SCREEN_HEIGHT));
    }

    bool quit = false;
    SDL_Event e;

    while (!quit) {
        while (SDL_PollEvent(&e) != 0) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
        }

        // Update drones
        updateDrones(drones);

        // Clear the screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); // Black color
        SDL_RenderClear(renderer);

        // Render drones
        renderDrones(renderer, drones);

        // Update the screen
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    
    return 0;
}
