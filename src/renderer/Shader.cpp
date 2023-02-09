#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include "glad/glad.h"
#include "Shader.h"

Shader::Shader(const char *vertexShaderPath, const char *fragmentShaderPath)
{
    std::string vertexShaderCode;
    std::string fragmentShaderCode;
    std::ifstream vertexShaderFile;
    std::ifstream fragmentShaderFile;

    try
    {
        vertexShaderFile.open(vertexShaderPath);
        fragmentShaderFile.open(fragmentShaderPath);
        std::stringstream vertexShaderStream, fragmentShaderStream;
        vertexShaderStream << vertexShaderFile.rdbuf();
        fragmentShaderStream << fragmentShaderFile.rdbuf();

        vertexShaderFile.close();
        fragmentShaderFile.close();

        vertexShaderCode = vertexShaderStream.str();
        fragmentShaderCode = fragmentShaderStream.str();

    } catch (std::ifstream::failure& err)
    {
        std::cerr << "COULD NOT READ SHADER FILE " << std::endl;
    }

    const GLchar* vertexShaderCodeRaw = vertexShaderCode.c_str();
    const GLchar* fragmentShaderCodeRaw = fragmentShaderCode.c_str();
    GLuint vertexShader, fragmentShader;

    vertexShader = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertexShader, 1, &vertexShaderCodeRaw, nullptr);
    glCompileShader(vertexShader);

    char infoLog[512];
    int success;
    glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(vertexShader, 512, nullptr, infoLog);
        std::cerr << "SHADER COMPILATION FAILURE " << infoLog << std::endl;
        exit(1);
    }

    // pretend we checkin errors here

    fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragmentShader, 1, &fragmentShaderCodeRaw, nullptr);
    glCompileShader(fragmentShader);

    glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);

    if (!success)
    {
        glGetShaderInfoLog(fragmentShader, 512, nullptr, infoLog);
        std::cerr << "SHADER COMPILATION FAILURE " << infoLog << std::endl;
        exit(1);
    }

    ID = glCreateProgram();
    glAttachShader(ID, vertexShader);
    glAttachShader(ID, fragmentShader);

    glLinkProgram(ID);

    glDeleteShader(vertexShader);
    glDeleteShader(fragmentShader);
}


void Shader::setVec2(const std::string &name, const glm::vec2 vector)
{
    glUniform2fv(glGetUniformLocation(ID, name.c_str()), 1, &vector[0]);
}

void Shader::use() const
{
    glUseProgram(ID);
}

void Shader::kill()
{
    glDeleteProgram(ID);
}
