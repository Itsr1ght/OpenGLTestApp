#include "Shader.h"
#include <glad/glad.h>
#include <glm/gtc/type_ptr.hpp>
#include <vector>
#include <fstream>
#include <sstream>
#include <iostream>

static Shader *instance;
std::string vertexCode;
std::string fragmentCode;

Shader::Shader(std::string* vertex_path, std::string* frag_path){
    vertexCode = fetchShader(*vertex_path);
    fragmentCode = fetchShader(*frag_path);
    compileShader();
    linkShader();
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader Shader::Create(std::string* vertex_path, std::string* frag_path)
{
    if (!instance)
        instance = new Shader(vertex_path, frag_path);
    return *instance;
}


std::string Shader::fetchShader(std::string path)
{
    std::fstream stream;
    std::string line;
    std::string file;

    stream.open(path);
    if (stream.is_open())
    {
        while (getline(stream, line)) {
            file += line + '\n';
        }
        stream.close();
    }
    return file;
}

bool Shader::compileShader()
{
    const char* vertex_source = vertexCode.c_str();
    const char* frag_source = fragmentCode.c_str();

    // vertex Shader
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vertex_source, NULL);
    glCompileShader(vertex);
    // print compile errors if any
    glGetShaderiv(vertex, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(vertex, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << &infoLog << std::endl;
        return false;
    };

    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &frag_source, NULL);
    glCompileShader(fragment);
    // print compile errors if any
    glGetShaderiv(fragment, GL_COMPILE_STATUS, &success);
    if (!success)
    {
        glGetShaderInfoLog(fragment, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << &infoLog << std::endl;
        return false;
    };
    return true;
}

bool Shader::linkShader()
{
    // shader Program
    ID = glCreateProgram();
    glAttachShader(ID, vertex);
    glAttachShader(ID, fragment);
    glLinkProgram(ID);
    // print linking errors if any
    glGetProgramiv(ID, GL_LINK_STATUS, &success);
    if (!success)
    {
        glGetProgramInfoLog(ID, 512, NULL, infoLog);
        std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
        return false;
    }
    return true;
}

void Shader::use() {
    glUseProgram(ID);
}

void Shader::setBool(const std::string& name, bool value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setInt(const std::string& name, int value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), value);
}

void Shader::setFloat(const std::string& name, float value) const {
    glUniform1i(glGetUniformLocation(ID, name.c_str()), (unsigned int)value);
}

void Shader::setMatrix4(const std::string& name, glm::mat4 matrix4) const
{
    glUniformMatrix4fv(glGetUniformLocation(ID, name.c_str()), 1, GL_FALSE, glm::value_ptr(matrix4));
}

void Shader::Destroy()
{
    glDeleteShader(vertex);
    glDeleteShader(fragment);
    free(instance);
}