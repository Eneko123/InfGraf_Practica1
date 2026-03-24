#pragma once
#include <iostream>

#include <glm/gtc/matrix_transform.hpp>

class Entity
{
public:
	Entity();
	virtual ~Entity();

	glm::vec3 GetPosition() { return position; };
	glm::vec3 GetRotation() { return rotation; };
	glm::vec3 GetScale() { return scale; };

	void SetPosition(float x, float y, float z) { position = glm::vec3(x, y, z); };
	void SetRotation(float x, float y, float z) { rotation = glm::vec3(x, y, z); };
	void SetScale(float x, float y, float z) { scale = glm::vec3(x, y, z); };

	glm::mat4 GetModelMatrix() const;

	virtual void Update(float deltaTime);

private:
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
};

