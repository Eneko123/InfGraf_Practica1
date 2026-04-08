#include "Entity.h"

Entity::Entity()
	: position(0.0f, 0.0f, 0.0f), rotation(0.0f, 0.0f, 0.0f), scale(1.0f, 1.0f, 1.0f)
{
}

Entity::~Entity()
{
}

glm::mat4 Entity::GetModelMatrix() const
{
	// Empezamos con una matriz identidad
	glm::mat4 model = glm::mat4(1.0f);

	// Aplicamos las transformaciones en orden: Traslacion -> Rotacion -> Escala
	// 1. Traslacion
	model = glm::translate(model, position);

	// 2. Rotaciones (en orden X, Y, Z)
	model = glm::rotate(model, glm::radians(rotation.x), glm::vec3(1.0f, 0.0f, 0.0f));
	model = glm::rotate(model, glm::radians(rotation.y), glm::vec3(0.0f, 1.0f, 0.0f));
	model = glm::rotate(model, glm::radians(rotation.z), glm::vec3(0.0f, 0.0f, 1.0f));

	// 3. Escala
	model = glm::scale(model, scale);

	return model;
}

void Entity::Update(float deltaTime)
{
}