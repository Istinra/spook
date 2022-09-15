//
// Created by Sam on 15/09/2022.
//

#include "Input.h"
#include "GLFW/glfw3.h"
#include "../Window.h"

bool isKeyPressed(KeyCodes key) {
    auto state = glfwGetKey(static_cast<GLFWwindow*>(Window::get().getNativeWindow()), static_cast<int32_t>(key));
    return state == GLFW_PRESS;
}