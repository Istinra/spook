//
// Created by Sam on 23/09/2022.
//

#include "Shader.h"
#include "glm/gtc/type_ptr.hpp"

Shader::Shader(const char *vertexShaderSource, const char *fragmentShaderSource) {
    GLint success = 0;
    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderSource, nullptr);
    glCompileShader(vertexShader);
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

//    static_assert(success == GL_FALSE, "A");

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderSource, nullptr);
    glCompileShader(fragmentShader);
    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    program = glCreateProgram();
    glAttachShader(program, vertexShader);
    glAttachShader(program, fragmentShader);
    glLinkProgram(program);

    GLint isLinked = 0;
    glGetProgramiv(program, GL_LINK_STATUS, (int *) &isLinked);
//TODO
}

Shader::~Shader() {
    glDeleteProgram(program);
    glDeleteShader(fragmentShader);
    glDeleteShader(vertexShader);
}

void Shader::bind() const {
    glUseProgram(program);
}

GLuint Shader::getProgram() const {
    return program;
}

void Shader::SetUniformMat4(const std::string &name, const glm::mat4 &matrix) {
    GLint location = glGetUniformLocation(program, name.c_str());
    glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
}
