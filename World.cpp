//
// Created by Alex on 23/09/2024.
//

#include "World.h"

World::World(int originX, int originY, int windowWidth) {
    grassBoundingBox = {-originX, 100, windowWidth, 100};
}

AABB World::getBoundingBox() const {
    return grassBoundingBox;
}
