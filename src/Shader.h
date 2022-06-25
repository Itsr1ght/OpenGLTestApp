#pragma once
#include <string>
#include <glm/matrix.hpp>

class Shader
{
public:
	Shader(const char* vertex_path,const char* frag_path);
	~Shader();
	void use();
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setMatrix4(const std::string& name , glm::mat4 matrix4) const;
private:
	unsigned int ID;
	unsigned int vertex=-1, fragment=-1;
	int success=0;
	char* infoLog=nullptr;
};

