#include "Entity.h"

Entity::Entity()
{
}

Entity::~Entity()
{
}

glm::mat4 Entity::GetModelMatrix() const
{
	return glm::mat4();
}

void Entity::Update(float deltaTime)
{
}
