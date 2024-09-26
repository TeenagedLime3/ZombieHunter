//
// Created by Alex on 23/09/2024.
//

#ifndef WORLD_H
#define WORLD_H
#include "AABB.h"


class World {
    AABB grassBoundingBox;

    public:
        World(int originX, int originY, int windowWidth);
        AABB getBoundingBox() const;

        void update();
        void render();
};



#endif //WORLD_H
