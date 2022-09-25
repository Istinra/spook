//
// Created by Sam on 25/09/2022.
//

#ifndef SPOOK_DEMOGAME_H
#define SPOOK_DEMOGAME_H


#include "../Application.h"

class DemoGame : public Application {

public:

    void onInit() override;

    void onUpdate(float time) override;

private:
    Camera camera;

};


#endif //SPOOK_DEMOGAME_H
