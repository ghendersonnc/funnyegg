

#include "VAO.h"

VAO::VAO()
{
    ID = 0;
    glGenVertexArrays(1, &ID);
}

void VAO::linkVBO(VBO &vbo, GLuint location)
{
    vbo.bind();
    glVertexAttribPointer(location, 2, GL_FLOAT, GL_FALSE, 0, (void*)0);
    glEnableVertexAttribArray(location);
    vbo.unbind();
}

void VAO::bind()
{
    glBindVertexArray(ID);
}

void VAO::unbind()
{
    glBindVertexArray(0);
}

void VAO::kill()
{
    glDeleteVertexArrays(1, &ID);
}
