//
// Created by Sam on 23/09/2022.
//

#include "Shader.h"

Shader::Shader(const char *vertexShaderSource, const char *fragmentShaderSource) {
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);

    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);
}

Shader::~Shader() {
    glDeleteProgram(program);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);
}

void Shader::bind() {
    glUseProgram(program);
}

GLuint Shader::getProgram() const {
    return program;
}
