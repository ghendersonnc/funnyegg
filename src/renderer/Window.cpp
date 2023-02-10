#include "Window.h"
#include <iostream>
Window::Window(int width, int height)
{
    m_Width = width;
    m_Height = height;
    p_Context = NULL;
    init();
    
}

void Window::init()
{
    if (!glfwInit())
    {
        std::cerr << "No GLFW :(" << std::endl;
        exit(1);
    }
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    p_Context = glfwCreateWindow(640, 480, "Hello", nullptr, nullptr);
    int x = 3;
    if (!p_Context)
    {
        std::cerr << "No Window Created" << std::endl;
        exit(1);
    }

    glfwMakeContextCurrent(p_Context);
    gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    glfwSetFramebufferSizeCallback(p_Context, [](GLFWwindow* window, int width, int height)
        {
            glViewport(0, 0, width, height);

        }
    );
}

