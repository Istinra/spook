//
// Created by Sam on 9/09/2022.
//

#include "Renderer.h"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/gtc/type_ptr.hpp"
#include "glm/mat4x4.hpp"
#include <memory>

static const struct {
    float x, y;
    float r, g, b;
} vertices[3] =
        {
                {-0.6f, -0.4f, 1.f, 0.f, 0.f},
                {0.6f,  -0.4f, 0.f, 1.f, 0.f},
                {0.f,   0.6f,  0.f, 0.f, 1.f}
        };

static const float verts[] = {-0.6f, -0.4f, 1.f, 0.f, 0.f, 0.6f, -0.4f, 0.f, 1.f, 0.f, 0.f, 0.6f, 0.f, 0.f, 1.f};

static const char *vertex_shader_text =
        R"(
        #version 110
        "uniform mat4 modelViewProjection;
        "attribute vec2 vPos;
        "attribute vec3 vCol;
        "varying vec3 color
        "void main()
        "{
        "    gl_Position = modelViewProjection * vec4(vPos, 0.0, 1.0);
        "    color = vCol;
        "}
    )";

static const char *fragment_shader_text = R"(
    "#version 110
    "varying vec3 color;
    "void main()
    "{
    "    gl_FragColor = vec4(color, 1.0);
    "}
)";

void Renderer::onInit() {
    BufferLayout layout = {
            {"vPos", 2, sizeof(float)},
            {"vCol", 3, sizeof(float)}
    };
    std::unique_ptr<VertexBuffer> vertexBuffer = std::make_unique<VertexBuffer>(verts, 14, layout);
    shader = std::make_unique<Shader>(vertex_shader_text, fragment_shader_text);
    GLint vpos_location = glGetAttribLocation(shader->getProgram(), "vPos");
    GLint vcol_location = glGetAttribLocation(shader->getProgram(), "vCol");
    vertexArray = std::make_unique<VertexArray>(std::move(vertexBuffer));
    mvp_location = glGetUniformLocation(shader->getProgram(), "modelViewProjection");
}

void Renderer::render(const Camera &camera, float time) {

    glClear(GL_COLOR_BUFFER_BIT);
    float ratio = 800 / (float) 600;
    glm::mat4x4 m = glm::identity<glm::mat4x4>();
    m = camera.getCameraTransform() * glm::rotate(m, time, glm::vec3(0.0f, 0.0f, 1.0f));
    glm::mat4x4 p = glm::ortho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glm::mat4x4 mvp = p * m;

    shader->bind();
    vertexArray->bind();

    glUniformMatrix4fv(mvp_location, 1, GL_FALSE, glm::value_ptr(mvp));
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
