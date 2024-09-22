#include <iostream>

//Axis Aligned Bounding Box
struct AABB {
    int x;
    int y;
    int width;
    int height;

    bool intersects(const AABB& aabb) const { //saying the method is constant
        if((aabb.x > x && aabb.x < x + width) && (aabb.y > y && aabb.y < y + height)) {
            std::cout << "inside!" << std::endl;
            return true;
        }

        return false;
    }
};