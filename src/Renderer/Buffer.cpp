//
// Created by Sam on 23/09/2022.
//

#include "Buffer.h"

#include <utility>

BufferLayoutElement::BufferLayoutElement(std::string name, uint32_t components, uint32_t componentSize) :
        name(std::move(name)),
        components(components),
        componentSize(componentSize),
        offset(0) {
}

BufferLayout::BufferLayout(const std::initializer_list<BufferLayoutElement> &eles) : elements(eles), stride(0) {
    for (auto &item: elements) {
        item.offset = stride;
        stride += item.components * item.componentSize;
    }
}

const std::vector<BufferLayoutElement> &BufferLayout::getElements() const {
    return elements;
}

uint32_t BufferLayout::getStride() const {
    return stride;
}

VertexBuffer::VertexBuffer(const float *vertices, uint32_t vertexCount, BufferLayout bufferLayout) : handle(0),
                                                                                                     layout(std::move(
                                                                                                             bufferLayout)) {
    glGenBuffers(1, &handle);
    glBindBuffer(GL_ARRAY_BUFFER, handle);
    uint32_t totalSize = layout.getStride() * vertexCount;
    glBufferData(GL_ARRAY_BUFFER, totalSize, vertices, GL_STATIC_DRAW);
}

void VertexBuffer::bind() {
    glBindBuffer(GL_ARRAY_BUFFER, handle);
}

GLuint VertexBuffer::getHandle() const {
    return handle;
}

const BufferLayout &VertexBuffer::getLayout() const {
    return layout;
}
