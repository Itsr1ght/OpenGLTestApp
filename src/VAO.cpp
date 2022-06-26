#include "VAO.h"
#include <glad/glad.h>

static VAO* instance;

VAO VAO::Create()
{
    if (!instance)
        instance = new VAO();
    return *instance;
}

void VAO::LinkVBO(VBO& vbo, unsigned int layout, unsigned int size, const void* pointer)
{

    vbo.bind();
    glVertexAttribPointer(layout, size, GL_FLOAT, GL_FALSE, 8 * sizeof(float), pointer);
    glEnableVertexAttribArray(layout);
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

void VAO::Destroy()
{
    glDeleteVertexArrays(1, &ID);
    delete instance;
}

VAO::VAO()
{
    glGenVertexArrays(1, &ID);
    glBindVertexArray(ID);
}