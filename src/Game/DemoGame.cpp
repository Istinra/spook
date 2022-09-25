//
// Created by Sam on 25/09/2022.
//

#include "DemoGame.h"
#include "glm/ext/matrix_transform.hpp"
#include "glm/ext/matrix_clip_space.hpp"

static const char *vertex_shader_text = R"(
    #version 330 core

    uniform mat4 modelViewProjection;

    layout(location = 0) in vec2 vPos;
    layout(location = 1) in vec3 vCol;

    out vec3 color;

    void main()
    {
        gl_Position = modelViewProjection * vec4(vPos, 0.0, 1.0);
        color = vCol;
    };
)";

static const char *fragment_shader_text = R"(
    #version 330 core

    in vec3 color;

    void main()
    {
        gl_FragColor = vec4(color, 1.0);
    };
)";

static const struct {
    float x, y;
    float r, g, b;
} vertices[3] =
        {
                {-0.6f, -0.4f, 1.f, 0.f, 0.f},
                {0.6f,  -0.4f, 0.f, 1.f, 0.f},
                {0.f,   0.6f,  0.f, 0.f, 1.f}
        };

DemoGame::DemoGame(): camera(800 / (float) 600) {}

void DemoGame::onInit() {
    Application::onInit();
    shader = std::make_unique<Shader>(vertex_shader_text, fragment_shader_text);
    BufferLayout layout = {
            {"vPos", 2, sizeof(float)},
            {"vCol", 3, sizeof(float)}
    };
    const float *v = (float *) &vertices;
    std::unique_ptr<VertexBuffer> vertexBuffer = std::make_unique<VertexBuffer>(v, 15, layout);
    vertexArray = std::make_unique<VertexArray>(std::move(vertexBuffer));
}

void DemoGame::onUpdate(float time) {
    Application::onUpdate(time);

    player.onUpdate(time);

    camera.setPosition(player.getPosition());

    Renderer::begin();
    Renderer::draw(*shader, *vertexArray, camera.getViewProjection());
}
