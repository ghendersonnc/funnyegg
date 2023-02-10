#include <iostream>
#include <glad/glad.h>
#include <glfw/glfw3.h>
#include "renderer/Shader.h"
#include "renderer/VBO.h"
#include "renderer/VAO.h"
#include "renderer/EBO.h"
#include "renderer/Shapes.h"
#include "renderer/Window.h"
#include <filesystem>

GLfloat R = 72.0f / 255;
GLfloat G = 47.0f / 255;
GLfloat B = 173.0f / 255;
GLfloat A = 1.0f;

int main()
{
    int x = 3;
    Window window(640, 480);

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
    while (!glfwWindowShouldClose(window.p_Context))
    {
        glClearColor(R, G, B, A);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        vao.bind();
        glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, nullptr);
//        glDrawArrays(GL_TRIANGLES, 0, 3);

        glfwSwapBuffers(window.p_Context);
        glfwPollEvents();
    }

    vao.kill();
    vbo.kill();
    ebo.kill();
    shader.kill();
    glfwDestroyWindow(window.p_Context);
    glfwTerminate();
}

