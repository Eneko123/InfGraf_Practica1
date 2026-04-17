#include "Object.h"
#include <glm/gtc/type_ptr.hpp>

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
	// 1. Activar el shader
	shader->useShader();

	// 2. Obtener la matriz modelo desde Entity
	glm::mat4 model = GetModelMatrix();

	// 3. Enviar las matrices al shader
	glUniformMatrix4fv(shader->GetIdModel(), 1, GL_FALSE, glm::value_ptr(model));
	glUniformMatrix4fv(shader->GetIdProjection(), 1, GL_FALSE, glm::value_ptr(projection));

	// 4. Renderizar la malla
	mesh.RenderMesh();

}