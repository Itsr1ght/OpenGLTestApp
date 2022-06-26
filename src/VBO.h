#pragma once
class VBO
{
public:
	static VBO Create(float *vertices, float size);
	void bind();
	void unbind();
	void Destroy();
private:
	VBO(float *vertices, float size);
	unsigned int ID = 0;
};

