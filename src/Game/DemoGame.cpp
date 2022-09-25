//
// Created by Sam on 25/09/2022.
//

#include "DemoGame.h"

DemoGame::DemoGame() : camera(800 / (float) 600) {}

void DemoGame::onInit() {
    Application::onInit();
    level.init();
}

void DemoGame::onUpdate(float time) {
    Application::onUpdate(time);

    level.onUpdate(time);

    camera.setPosition(glm::vec3(level.getPlayer().getPosition().x, 0.0f, 0));

    Renderer::begin();
    level.onRender(renderer, camera.getViewProjection());
}
