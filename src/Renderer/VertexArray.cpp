//
// Created by Sam on 23/09/2022.
//

#include "VertexArray.h"

VertexArray::VertexArray(std::unique_ptr<VertexBuffer> vb) : vertexBuffer(std::move(vb)), handle(0) {
    const BufferLayout &layout = vertexBuffer->getLayout();
    vertexBuffer->bind();

    glGenVertexArrays(1, &handle);
    glBindVertexArray(handle);

    int index = 0;
    for (const auto &item: layout.getElements()) {
        glEnableVertexAttribArray(index);
        glVertexAttribPointer(index, item.components, GL_FLOAT, GL_FALSE, layout.getStride(), (void *) item.offset);
        index++;
    }
}

VertexArray::~VertexArray() {
    glDeleteVertexArrays(1, &handle);
}

void VertexArray::bind() const {
    glBindVertexArray(handle);
}
