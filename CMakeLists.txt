cmake_minimum_required(VERSION 3.15)
project(MyOpenGLEngine LANGUAGES CXX C)

# Target modern C++20 standards
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# 1. Locate the OpenGL and GLFW system packages on Linux Mint
find_package(OpenGL REQUIRED)
find_package(glfw3 REQUIRED)

# 2. Define the executable FIRST (so CMake knows what 'MyOpenGLEngine' is)
add_executable(MyOpenGLEngine openg_l.cpp glad.c)

# 3. Tell CMake where to look for <glad/glad.h> AFTER creating the executable
target_include_directories(MyOpenGLEngine PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

# 4. Link the graphics libraries and system loaders dynamically
target_link_libraries(MyOpenGLEngine PRIVATE 
    glfw
    OpenGL::GL
    ${CMAKE_DL_LIBS}
)
