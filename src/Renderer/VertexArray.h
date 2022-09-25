//
// Created by Sam on 23/09/2022.
//

#ifndef SPOOK_VERTEXARRAY_H
#define SPOOK_VERTEXARRAY_H

#include <memory>
#include "Buffer.h"

class VertexArray {
public:
    explicit VertexArray(std::unique_ptr<VertexBuffer> vb);

    ~VertexArray();

    void bind() const;

    [[nodiscard]] uint32_t getVertexCount() const { return vertexBuffer->getVertexCount(); }

private:
    uint32_t handle;
    std::unique_ptr<VertexBuffer> vertexBuffer;
};


#endif //SPOOK_VERTEXARRAY_H
