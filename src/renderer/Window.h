#ifndef FUNNYEGG_WINDOW_H
#define FUNNYEGG_WINDOW_H
#include <glad/glad.h>
#include <glfw/glfw3.h>


class Window
{
public:
    GLFWwindow* p_Context;
    int m_Height;
    int m_Width;

    Window(int width, int height);
    void init();
private:
};
#endif