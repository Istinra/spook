//
// Created by Sam on 23/09/2022.
//

#include "Buffer.h"

VertexBuffer::VertexBuffer(const float *vertices, uint32_t count): handle(0) {
    glGenBuffers(1, &handle);
    glBindBuffer(GL_ARRAY_BUFFER, handle);
    uint32_t totalSize = sizeof(float) * count;
    glBufferData(GL_ARRAY_BUFFER, totalSize, vertices, GL_STATIC_DRAW);
}

void VertexBuffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, handle);
}

GLuint VertexBuffer::getHandle() const {
    return handle;
}
