

#ifndef FUNNYEGG_VBO_H
#define FUNNYEGG_VBO_H
#include "glad/glad.h"

class VBO
{
public:
    GLuint ID;
    VBO(GLfloat* vertices, GLsizeiptr size);
    void bind();
    void unbind();
    void kill();

};


#endif //FUNNYEGG_VBO_H
