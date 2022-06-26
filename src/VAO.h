#pragma once
#include "VBO.h"


class VAO
{
public:
	static VAO Create();
	void LinkVBO(VBO& vbo, unsigned int layout, unsigned int size, const void* pointer);
	void bind();
	void unbind();
	void Destroy();
	unsigned int ID = 0;
private:
	VAO();
};

