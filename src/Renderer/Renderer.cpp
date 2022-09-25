//
// Created by Sam on 9/09/2022.
//

#include "Renderer.h"
#include "glm/mat4x4.hpp"

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

void Renderer::onInit() {
    shader = std::make_unique<Shader>(vertex_shader_text, fragment_shader_text);
}

void Renderer::begin() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw(const VertexArray &vertexArray, const glm::mat4x4 &transform) {
    shader->bind();
    shader->setUniformMat4("modelViewProjection", transform);
    vertexArray.bind();
    glDrawArrays(GL_TRIANGLES, 0, (int) vertexArray.getVertexCount());
}
