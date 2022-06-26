#pragma once
#include <glm/glm.hpp>
#include "VBO.h"
#include "EBO.h"
#include "VAO.h"

struct Vertex
{
	glm::vec3 coord;
	glm::vec3 color;
	glm::vec2 texcoord;
};
