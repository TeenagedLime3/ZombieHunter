//
// Created by acsel on 06/09/2024.
//

#ifndef PLAYER_H
#define PLAYER_H

#include <SDL_render.h>


#include "Vector2i.h"
#include "World.h"
#include "AABB.h"


class Player {
    AABB boundingBox;
    Vector2i velocity;

    bool facingRight;
    
    public:
        Player();

        void handleInput(int key);
        void update(const World& world);
        void render(SDL_Renderer* renderer, int originX, int originY) const;
};

#endif //PLAYER_H
