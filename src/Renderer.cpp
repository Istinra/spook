//
// Created by Sam on 9/09/2022.
//

#include "Renderer.h"
#include "glm/ext/matrix_clip_space.hpp"
#include "glm/gtc/type_ptr.hpp"
#include <glm/mat4x4.hpp>
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
        "#version 110\n"
        "uniform mat4 MVP;\n"
        "attribute vec3 vCol;\n"
        "attribute vec2 vPos;\n"
        "varying vec3 color;\n"
        "void main()\n"
        "{\n"
        "    gl_Position = MVP * vec4(vPos, 0.0, 1.0);\n"
        "    color = vCol;\n"
        "}\n";

static const char *fragment_shader_text =
        "#version 110\n"
        "varying vec3 color;\n"
        "void main()\n"
        "{\n"
        "    gl_FragColor = vec4(color, 1.0);\n"
        "}\n";

void Renderer::onInit() {
    vertexBuffer = std::make_unique<VertexBuffer>(verts, 14);
    shader = std::make_unique<Shader>(vertex_shader_text, fragment_shader_text);
    mvp_location = glGetUniformLocation(shader->getProgram(), "MVP");
    vpos_location = glGetAttribLocation(shader->getProgram(), "vPos");
    vcol_location = glGetAttribLocation(shader->getProgram(), "vCol");

    vertexBuffer->bind();
    glEnableVertexAttribArray(vpos_location);
    glVertexAttribPointer(vpos_location, 2, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void *) 0);
    glEnableVertexAttribArray(vcol_location);
    glVertexAttribPointer(vcol_location, 3, GL_FLOAT, GL_FALSE,
                          sizeof(vertices[0]), (void *) (sizeof(float) * 2));
}

void Renderer::render(const Camera &camera, float time) {

    glClear(GL_COLOR_BUFFER_BIT);
    float ratio = 800 / (float) 600;
    glm::mat4x4 m = glm::identity<glm::mat4x4>();
    m = camera.getCameraTransform() * glm::rotate(m, time, glm::vec3(0.0f, 0.0f, 1.0f));
    glm::mat4x4 p = glm::ortho(-ratio, ratio, -1.f, 1.f, 1.f, -1.f);
    glm::mat4x4 mvp = p * m;

    glUseProgram(shader->getProgram());
    glUniformMatrix4fv(mvp_location, 1, GL_FALSE, glm::value_ptr(mvp));
    glDrawArrays(GL_TRIANGLES, 0, 3);
}
