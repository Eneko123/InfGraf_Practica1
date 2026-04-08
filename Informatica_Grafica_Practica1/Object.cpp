#include "Object.h"

Object::Object()
{
}

Object::Object(Shader* shader)
{
	this->shader = shader;
}

Object::~Object()
{
}

void Object::Render(const glm::mat4& projection)
{
	shader->useShader();
	shader->GetIdModel();
	mesh.RenderMesh();
}