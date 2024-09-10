//
// Created by acsel on 06/09/2024.
//

#ifndef PLAYER_H
#define PLAYER_H
#include "Vector2i.h"


class Player {
    Vector2i position;
    Vector2i velocity;

    bool facingRight;

    public:
        int getXCoordinate();
        int getYCoordinate();
        bool isFacingRight();

        void handleInput(int key);
};

#endif //PLAYER_H
