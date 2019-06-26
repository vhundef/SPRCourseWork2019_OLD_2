//
// Created by vhundef on 25.06.19.
//

#ifndef COURSEWORK_SHIP_H
#define COURSEWORK_SHIP_H

#include <SDL/SDL.h>
#include <SDL/SDL_draw.h>
#include "GameObject.h"
#include "ScreenManager.h"
#include <list>

using namespace std;

class Ship : GameObject {
protected:
    int health{0}, movementDirection{0}, movementSpeed{0};

    ScreenManager *screenManager = nullptr;
    coords location;
    SDL_Rect body;
    int bodyColor = 0x727272;

    void updateLocation() {
        location.x1 += movementDirection * movementSpeed;


        //TODO: make relative

        // ==== Location checks (so that player won't go off screen) ==== //
        if ((location.x1 >= 1190) && movementDirection == 1)
            location.x1 -= 1150;

        if ((location.x1 < 0) && movementDirection == -1)
            location.x1 += 1200;

        location.x2 = location.x1 + body.w;
    }

public:
    coords getCoords() {
        return location;
    }

    void setHealth(int deltaHealth) {
        health += deltaHealth;
    }
};


#endif //COURSEWORK_SHIP_H
