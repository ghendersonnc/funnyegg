#include <iostream>
#include "glad/glad.h"
#include "GLFW/glfw3.h"

GLfloat R = 72.0f/255;
GLfloat G = 47.0f/255;
GLfloat B = 173.0f/255;
GLfloat A = 1.0f;

int main()
{
    if (!glfwInit())
    {
        std::cerr << "no glfw for u" << std::endl;
        exit(1);
    }

    GLFWwindow* window = glfwCreateWindow(640, 480, "Balls", NULL, NULL);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    if (!window)
    {
        std::cerr << "no window for u" << std::endl;
        exit(1);
    }
    glfwMakeContextCurrent(window);
    gladLoadGLLoader((GLADloadproc) glfwGetProcAddress);

    while (!glfwWindowShouldClose(window))
    {
        glClearColor(R, G, B, A);
        glClear(GL_COLOR_BUFFER_BIT);

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwDestroyWindow(window);
    glfwTerminate();
}
