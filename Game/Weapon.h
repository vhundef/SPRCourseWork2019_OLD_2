//
// Created by vhundef on 01.07.19.
//

#ifndef COURSEWORK_WEAPON_H
#define COURSEWORK_WEAPON_H


#include <list>
#include "GameObject.h"
#include "Ship.h"

class Particle : public GameObject {
private:
    bool bIsOnScreen{true};
    ScreenManager *screenManager;
    SDL_Rect particle;
public:
    Particle() {
        bIsOnScreen = true;
        initialsed = false;
    }

    void init(ScreenManager *screenMgr, coords loc) {
        cout << "Particle was spawned: " << this << endl;
        particle.h = 10;
        particle.w = 5;
        particle.x = (loc.x1 + loc.x2) / 2;
        particle.y = (loc.y1 + loc.y2) / 2;
        screenManager = screenMgr;
        initialsed = true;
    }

    bool isOnScreen() const {
        return bIsOnScreen;
    }

    void setIsOnScreem(bool OnScreen) {
        Particle::bIsOnScreen = OnScreen;
    }

    void reDraw() {
        if (!initialsed) throw runtime_error("ERROR: attempt to call reDraw on uninitialised Particle instance\n");
        updatelocation();
        // cout<<"Particle("<<this<<") trying to get screenManager->mainSurface...";
        SDL_FillRect(screenManager->getMainSurface(), &particle, 0xffff);
        // cout<<"OK"<<endl;

    }

private:
    void updatelocation() {

    }
};

class Weapon : public GameObject {
private:
    int ammo{40}, power{1};
    ScreenManager *screenManager;
    list <Particle> particles;
    bool bIsEnemy{true};
public:
    void init(ScreenManager *screenMgr, bool isEnemy) {
        cout << "Weapon was spawned: " << this << endl;
        screenManager = screenMgr;
        bIsEnemy = isEnemy;
        initialsed = true;
    }

    Weapon() {
        initialsed = false;
    }

    int getPower() const {
        return power;
    }

    void setPower(int pwr) {
        Weapon::power = pwr;
    }

    void shoot() {
        if (!initialsed) throw runtime_error("ERROR: attempt to call shoot on uninitialised Weapon instance\n");
        particles.push_back(*new Particle());
        particles.back().init(screenManager, location);
    }

    int getAmmo() const {
        return ammo;
    }

    void setAmmo(int ammoAmount) {
        Weapon::ammo = ammoAmount;
    }

    void update(coords newloc) {
        location = newloc;
        if (!particles.empty())
            for (auto &particle : particles) {
                particle.reDraw();
            }
    }

};


#endif //COURSEWORK_WEAPON_H
