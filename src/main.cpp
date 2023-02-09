#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "renderer/Shader.h"
#include "renderer/VBO.h"
#include "renderer/VAO.h"
#include "renderer/EBO.h"
#include "renderer/Shapes.h"
#include <filesystem>

void frameBufferSizeCallback(GLFWwindow* window, int width, int height);

GLfloat R = 72.0f / 255;
GLfloat G = 47.0f / 255;
GLfloat B = 173.0f / 255;
GLfloat A = 1.0f;

int main()
{
    if (!glfwInit())
    {
        std::cerr << "no glfw for u" << std::endl;
        exit(1);
    }

    GLFWwindow *window = glfwCreateWindow(640, 480, "FunnyEgg", nullptr, nullptr);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    if (!window)
    {
        std::cerr << "no window for u" << std::endl;
        exit(1);
    }
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);
    glfwSetFramebufferSizeCallback(window, frameBufferSizeCallback);
    Shader shader("shaders/shader.vert", "shaders/shader.frag");


    // Bind VAO first
    VAO vao;
    vao.bind();

    VBO vbo(Shapes::Vertex::TRIFORCE, sizeof(Shapes::Vertex::TRIFORCE));
    EBO ebo(Shapes::Index::TRIFORCE, sizeof(Shapes::Index::TRIFORCE));

    vao.linkVBO(vbo, 0);
    vao.unbind();
    vbo.unbind();
    ebo.unbind();

    glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
    while (!glfwWindowShouldClose(window))
    {
        glClearColor(R, G, B, A);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        vao.bind();
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, nullptr);
//        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    vao.kill();
    vbo.kill();
    ebo.kill();
    shader.kill();
    glfwDestroyWindow(window);
    glfwTerminate();
}

void frameBufferSizeCallback(GLFWwindow* window, int width, int height)
{
    glViewport(0, 0, width, height);
}