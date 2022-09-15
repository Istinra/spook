//
// Created by Sam on 9/09/2022.
//

#ifndef SPOOK_CAMERA_H
#define SPOOK_CAMERA_H

#include "glm/mat4x4.hpp"

class Camera {
public:
    Camera();
    void onUpdate(float d);

    const glm::mat4x4 &getCameraTransform() const;

private:
    glm::mat4x4 cameraTransform;
};


#endif //SPOOK_CAMERA_H
