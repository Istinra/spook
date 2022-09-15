//
// Created by Sam on 9/09/2022.
//

#include "Camera.h"
#include "glm/ext/matrix_transform.hpp"
#include "Input/Input.h"

Camera::Camera() : cameraTransform(glm::identity<glm::mat4x4>()) {
}

void Camera::onUpdate(float d) {
    if (isKeyPressed(KeyCodes::A)) {
        cameraTransform = glm::translate(cameraTransform, glm::vec3(-0.1f, 0, 0));
    } else if (isKeyPressed(KeyCodes::D)) {
        cameraTransform = glm::translate(cameraTransform, glm::vec3(0.1f, 0, 0));
    } else if (isKeyPressed(KeyCodes::W)) {
        cameraTransform = glm::translate(cameraTransform, glm::vec3(0, 0.1f, 0));
    } else if (isKeyPressed(KeyCodes::S)) {
        cameraTransform = glm::translate(cameraTransform, glm::vec3(0, -0.1f, 0));
    }
}

const glm::mat4x4 &Camera::getCameraTransform() const {
    return cameraTransform;
}
