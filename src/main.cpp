#define GLFW_INCLUDE_NONE

#include <GLFW/glfw3.h>
#include "Window.h"
#include "Game/DemoGame.h"

int main() {

    Window window;
    window.initialiseWindow();
    Window::instance = &window;

    DemoGame app;
    app.onInit();

    while (!glfwWindowShouldClose(static_cast<GLFWwindow*>(window.getNativeWindow()))) {
        app.onUpdate((float) glfwGetTime());
        glfwSwapBuffers(static_cast<GLFWwindow*>(window.getNativeWindow()));
        glfwPollEvents();
    }

    return 0;
}
