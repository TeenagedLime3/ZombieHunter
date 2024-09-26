//
// Created by acsel on 06/09/2024.
//

#include "Player.h"
#include <SDL.h>

Player::Player() {
    boundingBox = {0, 400, 100, 200};
}

void Player::handleInput(int key) {
    switch(key) {
        case SDLK_UP:
        case SDLK_w:
        case SDLK_SPACE:
            velocity.y += 50;
            break;
        case SDLK_d:
        case SDLK_RIGHT:
            facingRight = true;
            velocity.x += 20;
            break;
        case SDLK_a:
        case SDLK_LEFT:
            facingRight = false;
            velocity.x -= 20;
        break;
    }
}

void Player::update(const World& world) {
    if(!boundingBox.intersects(world.getBoundingBox())) {
        velocity.y -= 5;
    } else {
        std::cout << "Intersecting" << std::endl;
        velocity.y = 0;
    }

    boundingBox.x += velocity.x /= 2;
    boundingBox.y += velocity.y /= 2;
}

void Player::render(SDL_Renderer* renderer, int originX, int originY) const {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect playerRender(originX + boundingBox.x, originY - boundingBox.y, boundingBox.width, boundingBox.height);
    SDL_RenderFillRect(renderer, &playerRender);
}