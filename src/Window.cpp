//
// Created by Sam on 15/09/2022.
//

#include "Window.h"
#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>

Window* Window::instance = nullptr;

Window::Window(): window(nullptr) {
}

Window::~Window() {
    if (window) {
        glfwDestroyWindow(static_cast<GLFWwindow*>(window));
    }
    glfwTerminate();
}

void onError(int error, const char *description) {
    std::cout << error << " glfw failure " << description;
}

void keyPressCallback(GLFWwindow *window, int key, int scancode, int action, int mods) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
        glfwSetWindowShouldClose(window, GLFW_TRUE);
}

bool Window::initialiseWindow() {
    if (!glfwInit())
        return false;
    glfwSetErrorCallback(onError);
    GLFWwindow* glfwWindow = glfwCreateWindow(800, 600, "My Title", NULL, NULL);
    if (!glfwWindow)
        return false;

    glfwSetKeyCallback(glfwWindow, keyPressCallback);
    glfwMakeContextCurrent(glfwWindow);
    gladLoadGL();
    glfwSwapInterval(1);

    int width, height;
    glfwGetFramebufferSize(glfwWindow, &width, &height);
    glViewport(0, 0, width, height);

    window = glfwWindow;

    return true;
}

Window &Window::get() {
    return *instance;
}

void* Window::getNativeWindow() const {
    return window;
}
