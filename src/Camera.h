//
// Created by Sam on 9/09/2022.
//

#ifndef SPOOK_CAMERA_H
#define SPOOK_CAMERA_H


#include "../Vendor/glfw-3.3.8/deps/linmath.h"

class Camera {
public:
    Camera();
    void onEvent();

private:
    mat4x4 view;
};


#endif //SPOOK_CAMERA_H
