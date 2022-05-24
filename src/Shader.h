#pragma once
#include <string>

class Shader
{
public:
	Shader(const char* vertex_path,const char* frag_path);
	~Shader();
	void use();
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
private:
	unsigned int ID;
	unsigned int vertex, fragment;
	int success;
	char infoLog[512];
};

