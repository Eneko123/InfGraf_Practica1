#pragma once

#include <iostream>

#include "Mesh.h"
#include "Shader.h"
#include "Entity.h"

class Object : Entity
{
public:
	Object();
	Object(Shader* shader);
	virtual ~Object();

	virtual void Init() = 0;
	virtual void Render(const glm::mat4& projection);

private:
	Mesh mesh;
	Shader* shader;
};

