//
// Created by Sam on 23/09/2022.
//

#ifndef SPOOK_SHADER_H
#define SPOOK_SHADER_H

#include <glad/glad.h>
#include <string>
#include "glm/ext/matrix_float4x4.hpp"

class Shader {

public:
    Shader(const char* vertexShaderSource, const char* fragmentShaderSource);
    ~Shader();

    void bind() const;

    GLuint getProgram() const;

    void SetUniformMat4(const std::string& name, const glm::mat4& matrix);

private:
    GLuint vertexShader;
    GLuint fragmentShader;
    GLuint program;

};

#endif //SPOOK_SHADER_H
