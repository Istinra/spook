//
// Created by Sam on 25/09/2022.
//

#ifndef SPOOK_DEMOGAME_H
#define SPOOK_DEMOGAME_H


#include "../Application.h"
#include "Player.h"
#include "Level.h"

class DemoGame : public Application {

public:
    DemoGame();

    void onInit() override;

    void onUpdate(float time) override;

private:
    Level level;
    Camera camera;
};


#endif //SPOOK_DEMOGAME_H
