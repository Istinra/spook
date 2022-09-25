//
// Created by Sam on 9/09/2022.
//

#ifndef SPOOK_APPLICATION_H
#define SPOOK_APPLICATION_H

#include "Camera.h"
#include "Renderer/Renderer.h"

class Application {

public:
    Application() = default;
    virtual ~Application() = default;
    virtual void onInit();
    virtual void OnEvent();
    virtual void onUpdate(float time);

protected:
    Renderer renderer;
};

#endif //SPOOK_APPLICATION_H
