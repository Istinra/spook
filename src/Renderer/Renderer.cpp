//
// Created by Sam on 9/09/2022.
//

#include "Renderer.h"
#include "glm/mat4x4.hpp"

void Renderer::onInit() {
}

void Renderer::begin() {
    glClear(GL_COLOR_BUFFER_BIT);
}

void Renderer::draw(const Shader &shader, const VertexArray &vertexArray, const glm::mat4x4 &transform) {
    shader.bind();
    shader.setUniformMat4("modelViewProjection", transform);
    vertexArray.bind();
    glDrawArrays(GL_TRIANGLES, 0, (int) vertexArray.getVertexCount());
}
