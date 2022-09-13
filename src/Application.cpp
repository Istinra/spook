//
// Created by Sam on 9/09/2022.
//

#include "Application.h"

void Application::onInit() {
    renderer.onInit();
}

void Application::OnEvent() {
    camera.onEvent();
}

void Application::onUpdate(float time) {
    renderer.render(camera, time);
}
