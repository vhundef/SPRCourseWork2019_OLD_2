//
// Created by vhundef on 26.06.19.
//

#ifndef COURSEWORK_PLAYER_H
#define COURSEWORK_PLAYER_H

#include "Ship.h"

class Player : Ship {
private:
    int money{0};
    SDL_Rect body;
    int bodyColor = 0x727272;
    /**
     * @brief Update ship location according to speed and movement direction
     **/

public:
    explicit Player(ScreenManager *screenMgr) {
        screenManager = screenMgr;
        health = 100;
        movementDirection = 1;
        movementSpeed = 1;
        {
            body.w = 90;
            body.h = 35;
            body.x = 100;
            body.y = screenMgr->getScreenHeight() - 50;
            SDL_FillRect(screenMgr->getMainSurface(), &body, bodyColor);
        }
        location.x1 = body.x;
        location.x2 = body.x + body.w;
        location.y1 = body.y;
        location.y1 = body.y + body.h;
        money = 0;
    }

    void reDraw() {
        updateLocation();
        body.x = location.x1;
        SDL_FillRect(screenManager->getMainSurface(), &body, bodyColor);
    }

    /**
     * @param direction -1=left ; 1=right
     **/
    void setMovementDirection(int direction) {
        movementDirection = direction;
    }

    int getMoney() {
        return money;
    }
};


#endif //COURSEWORK_PLAYER_H
