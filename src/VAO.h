#pragma once
#include "VBO.h"


class VAO
{
public:
	static VAO Create();
	void LinkVBO(VBO& vbo, unsigned int layout, unsigned int size);
	void bind();
	void unbind();
	void Destroy();
	unsigned int ID = 0;
private:
	VAO();
};

