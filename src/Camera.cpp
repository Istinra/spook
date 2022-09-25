//
// Created by Sam on 9/09/2022.
//

#include "Camera.h"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/matrix_clip_space.hpp"

Camera::Camera(float aspectRatio): view(glm::identity<glm::mat4x4>()) {
    projection = glm::ortho(-aspectRatio, aspectRatio, -1.f, 1.f, 1.f, -1.f);
}

void Camera::setPosition(const glm::vec3 &position) {
    view = glm::translate(glm::identity<glm::mat4x4>(), position);
    viewProjection = projection * view;
}

const glm::mat4x4 &Camera::getProjection() const {
    return projection;
}

const glm::mat4x4 &Camera::getView() const {
    return view;
}

const glm::mat4x4 &Camera::getViewProjection() const {
    return viewProjection;
}

