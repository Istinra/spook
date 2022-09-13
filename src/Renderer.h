//
// Created by Sam on 9/09/2022.
//

#ifndef SPOOK_RENDERER_H
#define SPOOK_RENDERER_H


#include "Camera.h"
#include <glad/glad.h>

class Renderer {

public:
    void onInit();

    void render(const Camera &camera, float time);

private:
    GLuint vertex_buffer;
    GLuint vertex_shader;
    GLuint fragment_shader;
    GLuint program;
    GLint mvp_location;
    GLuint vpos_location;
    GLuint vcol_location;
};


#endif //SPOOK_RENDERER_H
