//
// Created by Sam on 25/09/2022.
//

#include "Player.h"
#include "../Input/Input.h"

Player::Player(): position(0) {}

void Player::onUpdate(float dt) {
    if (isKeyPressed(KeyCodes::A)) {
        position.x -= 0.1;
    } else if (isKeyPressed(KeyCodes::D)) {
        position.x += 0.1;
    } else if (isKeyPressed(KeyCodes::W)) {
        position.y += 0.1;
    } else if (isKeyPressed(KeyCodes::S)) {
        position.y -= 0.1;
    }
}

const glm::vec3 &Player::getPosition() const {
    return position;
}
