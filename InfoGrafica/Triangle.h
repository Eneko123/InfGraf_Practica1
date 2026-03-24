#pragma once

#include <iostream>

#include "Object.h"
#include "Shader.h"

class Triangle : Object
{
public:
	Triangle(Shader* shader);
	~Triangle();

	void Init() override;
};

