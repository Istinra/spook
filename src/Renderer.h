//
// Created by Sam on 9/09/2022.
//

#ifndef SPOOK_RENDERER_H
#define SPOOK_RENDERER_H


#include "Camera.h"
#include "Renderer/Shader.h"
#include "Renderer/Buffer.h"
#include "Renderer/VertexArray.h"
#include <glad/glad.h>
#include <memory>

class Renderer {

public:
    void onInit();

    void render(const Camera &camera, float time);

private:
    std::unique_ptr<Shader> shader;
    std::unique_ptr<VertexArray> vertexArray;
    GLint mvp_location;
};


#endif //SPOOK_RENDERER_H
