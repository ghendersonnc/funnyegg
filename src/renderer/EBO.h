#ifndef FUNNYEGG_EBO_H
#define FUNNYEGG_EBO_H
#include <glad/glad.h>

class EBO
{
public:
    GLuint ID;
    EBO(GLuint* indices, GLsizeiptr size);
    void bind();
    void unbind();
    void kill();
};


#endif //FUNNYEGG_EBO_H
