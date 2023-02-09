cmake_minimum_required(VERSION 3.24)
project(funnyegg)

set(CMAKE_CXX_STANDARD 20)
include_directories(includes)

# GLAD
add_library(glad STATIC includes/glad/glad.c)
target_include_directories(glad PUBLIC includes/glad)

# GLFW
set(GLFW_BUILD_DOCS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_TESTS OFF CACHE BOOL "" FORCE)
set(GLFW_BUILD_EXAMPLES OFF CACHE BOOL "" FORCE)
add_subdirectory(external/glfw)

# glm
add_subdirectory(external/glm)

# stb image
add_library(stb_image STATIC includes/stb_image/stb_image.cpp)
target_include_directories(stb_image PUBLIC includes/stb_image)

file(GLOB_RECURSE EXEC_SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${EXEC_SOURCES})

target_link_libraries(${PROJECT_NAME} PUBLIC
        glad
        glfw
        glm::glm
        )