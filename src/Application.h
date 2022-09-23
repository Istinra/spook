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
    void onInit();
    void OnEvent();
    void onUpdate(float time);
private:
    Camera camera;
    Renderer renderer;

};

#endif //SPOOK_APPLICATION_H
