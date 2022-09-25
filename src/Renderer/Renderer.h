//
// Created by Sam on 9/09/2022.
//

#ifndef SPOOK_RENDERER_H
#define SPOOK_RENDERER_H


#include "../Camera.h"
#include "Shader.h"
#include "Buffer.h"
#include "VertexArray.h"
#include "glad/glad.h"
#include <memory>

class Renderer {

public:
    void onInit();

    static void begin();

    void draw(const VertexArray &vertexArray, const glm::mat4x4 &transform);

private:
    std::unique_ptr<Shader> shader;
};


#endif //SPOOK_RENDERER_H
