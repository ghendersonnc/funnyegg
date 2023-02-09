#ifndef FUNNYEGG_SHADER_H
#define FUNNYEGG_SHADER_H
#include "glm/glm.hpp"

class Shader
{
public:
    GLuint ID;
    Shader(const char *vertexShaderPath, const char *fragmentShaderPath);

    void use() const;


    void setVec2(const std::string &name, const glm::vec2 vector);


    void kill();
};


#endif //FUNNYEGG_SHADER_H
