#pragma once
#include <string>
#include <glm/matrix.hpp>

class Shader
{
public:
	Shader(std::string* vertex_path, std::string* frag_path);
	~Shader();
	static Shader Create(std::string* vertex_path, std::string* frag_path);
	void use();
	void setBool(const std::string& name, bool value) const;
	void setInt(const std::string& name, int value) const;
	void setFloat(const std::string& name, float value) const;
	void setMatrix4(const std::string& name , glm::mat4 matrix4) const;
	void Destroy();
private:
	std::string fetchShader(std::string path);
	bool CompileShader();
	bool LinkShader();
	unsigned int ID;
	unsigned int vertex=-1, fragment=-1;
	int success=0;
	char* infoLog=nullptr;
};

