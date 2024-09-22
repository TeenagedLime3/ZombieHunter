//
// Created by acsel on 06/09/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include <SDL_rect.h>
#include <SDL_render.h>

#include "AABB.h"
#include "Vector2i.h"


class Player {
    AABB boundingBox = {0, 300, 100, 200};
    Vector2i velocity;

    bool facingRight;
    
    public:
        void handleInput(int key);
        void update();
        void render(SDL_Renderer* renderer, int originX, int originY);
};

#endif //PLAYER_H
