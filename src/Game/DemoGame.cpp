//
// Created by Sam on 25/09/2022.
//

#include "DemoGame.h"

void DemoGame::onInit() {
    Application::onInit();
}

void DemoGame::onUpdate(float time) {
    Application::onUpdate(time);
    camera.onUpdate(time);
    renderer.render(camera, time);
}
