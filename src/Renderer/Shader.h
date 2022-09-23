//
// Created by Sam on 23/09/2022.
//

#ifndef SPOOK_SHADER_H
#define SPOOK_SHADER_H

#include <glad/glad.h>

class Shader {

public:
    Shader(const char* vertexShaderSource, const char* fragmentShaderSource);
    ~Shader();

    void bind();

    GLuint getProgram() const;

private:
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint program;

};

#endif //SPOOK_SHADER_H
