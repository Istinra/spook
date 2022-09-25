//
// Created by Sam on 23/09/2022.
//

#ifndef SPOOK_BUFFER_H
#define SPOOK_BUFFER_H


#include <string>
#include <vector>
#include "glad/glad.h"

struct BufferLayoutElement {
    std::string name;
    uint32_t components;
    uint32_t componentSize;
    uint32_t offset;

    BufferLayoutElement(std::string name, uint32_t components, uint32_t componentSize);
};

class BufferLayout {

public:
    BufferLayout(const std::initializer_list<BufferLayoutElement> &elements);

    [[nodiscard]] const std::vector<BufferLayoutElement> &getElements() const;

    [[nodiscard]] uint32_t getStride() const;

private:
    std::vector<BufferLayoutElement> elements;
    uint32_t stride;
};

class VertexBuffer {

public:
    explicit VertexBuffer(const float *vertices, uint32_t vertexCount, BufferLayout bufferLayout);

    void bind() const;

    [[nodiscard]] GLuint getHandle() const;

    [[nodiscard]] const BufferLayout &getLayout() const;

    uint32_t getVertexCount() const;

private:
    GLuint handle;
    BufferLayout layout;
    uint32_t vertexCount;
};


#endif //SPOOK_BUFFER_H
