#pragma once
#include <string>
#include <glm/matrix.hpp>

class Shader
{
public:
	static Shader Create(std::string* vertex_path, std::string* frag_path);
	void use();
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setMatrix4(const std::string& name , glm::mat4 matrix4) const;
	void Destroy();
private:
	Shader(std::string* vertex_path, std::string* frag_path);
	std::string fetchShader(std::string path);
	bool compileShader();
	bool linkShader();
	unsigned int ID;
	unsigned int vertex=-1, fragment=-1;
	int success=0;
	char infoLog[512];
};

