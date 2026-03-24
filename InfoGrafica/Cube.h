#pragma once

#include <iostream>

#include "Object.h"
#include "Shader.h"

class Cube : Object
{
public:
	Cube(Shader* shader);
	void Init() override;
	void Update(float deltaTime) override;
};

