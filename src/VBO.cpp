#include "VBO.h"
#include <glad/glad.h>
#include <memory>

static VBO *instance=0;

VBO VBO::Create(float *vertices, float size)
{
    if (!instance)
        instance = new VBO(vertices, size);
    return *instance;
}
void VBO::bind()
{
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::unbind()
{
    glBindBuffer(GL_ARRAY_BUFFER, ID);
}

void VBO::Destroy()
{
    glDeleteBuffers(1, &ID);
    if (instance)
        delete instance;
}

VBO::VBO(float *vertices, float size)
{
    glGenBuffers(1, &ID);
    //Bind the generated buffer to array buffer
    glBindBuffer(GL_ARRAY_BUFFER, ID);
    //Convert the user data to currently bounded buffer
    glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

