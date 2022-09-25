cmake_minimum_required(VERSION 3.23)
project(spook)

set(CMAKE_CXX_STANDARD 20)

add_executable(spook src/main.cpp
        Vendor/glad/src/glad.c src/Renderer/Renderer.cpp src/Camera.cpp src/Application.cpp src/Input/Input.cpp src/Window.cpp src/Renderer/Shader.cpp src/Renderer/Shader.h src/Renderer/Buffer.cpp src/Renderer/Buffer.h src/Renderer/VertexArray.cpp src/Game/DemoGame.cpp src/Game/DemoGame.h)

target_include_directories(spook PRIVATE
        Vendor/glfw-3.3.8/include
        Vendor/glad/include
        Vendor/glm
)

add_subdirectory(Vendor/glfw-3.3.8)
add_subdirectory(Vendor/glm)
target_link_libraries(spook glfw glm)