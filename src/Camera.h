//
// Created by Sam on 9/09/2022.
//

#ifndef SPOOK_CAMERA_H
#define SPOOK_CAMERA_H

#include "glm/mat4x4.hpp"

class Camera {
public:
    Camera(float aspectRatio);

    void setPosition(const glm::vec3& position);

    const glm::mat4x4 &getProjection() const;

    const glm::mat4x4 &getView() const;

    const glm::mat4x4 &getViewProjection() const;

private:
    glm::mat4x4 projection;
    glm::mat4x4 view;
    glm::mat4x4 viewProjection;
};


#endif //SPOOK_CAMERA_H
