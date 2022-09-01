cmake_minimum_required(VERSION 3.23)
project(spook)

set(CMAKE_CXX_STANDARD 20)

add_executable(spook src/main.cpp)

target_include_directories(spook PRIVATE
        Vendor/glfw-3.3.8/include
        Vendor/glfw-3.3.8/deps
)

add_subdirectory(Vendor/glfw-3.3.8)
target_link_libraries(spook glfw)