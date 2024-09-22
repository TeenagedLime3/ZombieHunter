//
// Created by acsel on 06/09/2024.
//

#include "Player.h"
#include <SDL.h>

void Player::handleInput(int key) {
    switch(key) {
        case SDLK_UP:
        case SDLK_w:
        case SDLK_SPACE:
            boundingBox.y += 50;
            break;
        case SDLK_d:
        case SDLK_RIGHT:
            facingRight = true;
            boundingBox.x += 50;
            break;
        case SDLK_a:
        case SDLK_LEFT:
            facingRight = false;
            boundingBox.x -= 50;
            break;
        case SDLK_s:
        case SDLK_DOWN:
            facingRight = false;
            boundingBox.y -= 50;
            break;
    }
}

void Player::update() {

}

void Player::render(SDL_Renderer* renderer, int originX, int originY) {
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_Rect playerRender(originX + boundingBox.x, originY - boundingBox.y, boundingBox.width, boundingBox.height);
    SDL_RenderFillRect(renderer, &playerRender);
}