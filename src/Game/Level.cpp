//
// Created by Sam on 25/09/2022.
//

#include "Level.h"
#include "glm/mat4x4.hpp"
#include "glm/gtx/transform.hpp"

static const struct {
    float x, y;
    float r, g, b;
} vertices[3] =
        {
                {-0.6f, 0,    1.f, 0.f, 0.f},
                {0.6f,  0,    0.f, 1.f, 0.f},
                {0.f,   1.0f, 0.f, 0.f, 1.f}
        };

Level::Level() = default;

const Player &Level::getPlayer() const {
    return player;
}

void Level::init() {
    BufferLayout layout = {
            {"vPos", 2, sizeof(float)},
            {"vCol", 3, sizeof(float)}
    };
    const float *v = (float *) &vertices;
    std::unique_ptr<VertexBuffer> vertexBuffer = std::make_unique<VertexBuffer>(v, 15, layout);
    vertexArray = std::make_unique<VertexArray>(std::move(vertexBuffer));

    for (int i = 0; i < 4; ++i) {
        mountains.push_back({{0 + 0.3f * (float) i, -1}, 1});
    }
}

void Level::onUpdate(float time) {
    player.onUpdate(time);
}

void Level::onRender(Renderer &renderer, const glm::mat4x4 &viewProjection) {

    renderer.draw(*vertexArray, viewProjection);

    for (const auto &item: mountains) {
        auto matrix = glm::translate(glm::identity<glm::mat4x4>(), glm::vec3(item.position, 0));
        renderer.draw(*vertexArray, matrix * viewProjection);
    }
}
