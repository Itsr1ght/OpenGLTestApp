#pragma once
class EBO
{
public:
	static EBO Create(unsigned int* indices,int size);
	void bind();
	void unbind();
	void Destroy();
private:
	EBO(unsigned int* vertices ,int size);
	unsigned int ID = 0;
};

