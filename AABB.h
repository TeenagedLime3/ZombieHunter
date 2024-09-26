#ifndef AABB_H
#define AABB_H

#include <iostream>

//Axis Aligned Bounding Box
struct AABB {
    int x;
    int y;
    int width;
    int height;

    bool intersects(const AABB& aabb) const { //saying the method is constant
        return x < aabb.x + aabb.width &&
            x + width > aabb.x &&
            y < aabb.y + aabb.height &&
            y + height > aabb.x;
    }
};

#endif