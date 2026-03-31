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
	Entity rotation;
	rotation.GetRotation().y += velocidad * deltaTime;
}
