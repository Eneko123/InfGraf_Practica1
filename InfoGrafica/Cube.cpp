#include "Cube.h"

Cube::Cube(Shader* shader)
{
}

void Cube::Init()
{
}

void Cube::Update(float deltaTime)
{
	float velocidad = 5.0f;
	cube.GetRotation().y += velocidad * deltaTime;
}
