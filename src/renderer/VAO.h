

#ifndef FUNNYEGG_VAO_H
#define FUNNYEGG_VAO_H
#include "glad/glad.h"
#include "VBO.h"
class VAO
{
public:
    GLuint ID;
    VAO();
    void bind();
    void unbind();
    void linkVBO(VBO& vbo, GLuint location);
    void kill();
};


#endif //FUNNYEGG_VAO_H
