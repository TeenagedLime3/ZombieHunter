//
// Created by acsel on 06/09/2024.
//

#include "Player.h"
#include <SDL.h>

int Player::getXCoordinate() {
    return position.x;
}
int Player::getYCoordinate() {
    return position.y;
}
bool Player::isFacingRight() {
    return facingRight;
}

void Player::handleInput(int key) {
    switch(key) {
        case SDLK_UP:
        case SDLK_w:
        case SDLK_SPACE:
            position.y += 50;
            break;
        case SDLK_d:
        case SDLK_RIGHT:
            facingRight = true;
            position.x += 50;
            break;
        case SDLK_a:
        case SDLK_LEFT:
            facingRight = false;
            position.x -= 50;
            break;
        case SDLK_s:
        case SDLK_DOWN:
            facingRight = false;
            position.y -= 50;
            break;
    }
}