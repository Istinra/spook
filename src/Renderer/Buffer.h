//
// Created by Sam on 23/09/2022.
//

#ifndef SPOOK_BUFFER_H
#define SPOOK_BUFFER_H


#include "glad/glad.h"

class VertexBuffer {

public:
    explicit VertexBuffer(const float *vertices, uint32_t count);

    void bind();

    [[nodiscard]] GLuint getHandle() const;

private:
    GLuint handle;
};


#endif //SPOOK_BUFFER_H
