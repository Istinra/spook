#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include "Application.h"
#include "Window.h"

int main() {

    Window window;
    window.initialiseWindow();
    Window::instance = &window;

    Application app;
    app.onInit();

    while (!glfwWindowShouldClose(static_cast<GLFWwindow*>(window.getNativeWindow()))) {
        app.onUpdate((float) glfwGetTime());
        glfwSwapBuffers(static_cast<GLFWwindow*>(window.getNativeWindow()));
        glfwPollEvents();
    }

    return 0;
}
