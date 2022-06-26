#include "EBO.h"
#include <glad/glad.h>
#include <iostream>

static EBO* instance=0;

EBO EBO::Create(unsigned int* indices, int size)
{
    if (!instance)
        instance = new EBO(indices,size);
    return *instance;
}
void EBO::bind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
}

void EBO::unbind()
{
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void EBO::Destroy()
{
    glDeleteBuffers(1, &ID);
    if (instance)
        delete instance;
}

EBO::EBO(unsigned int* indices,int size)
{
    glGenBuffers(1, &ID);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, indices, GL_STATIC_DRAW);
}