//
// Created by Sam on 23/09/2022.
//

#ifndef SPOOK_VERTEXARRAY_H
#define SPOOK_VERTEXARRAY_H

#include <memory>
#include "Buffer.h"

class VertexArray {
public:
    explicit VertexArray(std::unique_ptr<VertexBuffer> vertexBuffer);
    ~VertexArray();

    void bind() const;

private:
    uint32_t handle;
    std::unique_ptr<VertexBuffer> vertexBuffer;
};


#endif //SPOOK_VERTEXARRAY_H
