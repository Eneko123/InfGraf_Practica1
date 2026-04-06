#include "Cube.h"

Cube::Cube(Shader* shader)
	: Object(shader)
{
}

void Cube::Init()
{
	// Definimos los 8 vertices del cubo
	// Un cubo tiene 8 esquinas
	GLfloat vertices[] = {
		// Cara frontal (z = 1)
		-1.0f, -1.0f,  1.0f,  // 0: abajo izquierda frontal
		 1.0f, -1.0f,  1.0f,  // 1: abajo derecha frontal
		 1.0f,  1.0f,  1.0f,  // 2: arriba derecha frontal
		-1.0f,  1.0f,  1.0f,  // 3: arriba izquierda frontal

		// Cara trasera (z = -1)
		-1.0f, -1.0f, -1.0f,  // 4: abajo izquierda trasera
		 1.0f, -1.0f, -1.0f,  // 5: abajo derecha trasera
		 1.0f,  1.0f, -1.0f,  // 6: arriba derecha trasera
		-1.0f,  1.0f, -1.0f   // 7: arriba izquierda trasera
	};

	// Definimos los indices para las 6 caras (cada cara = 2 triangulos = 6 indices)
	// Total: 6 caras * 6 indices = 36 indices
	GLuint indices[] = {
		// Cara frontal
		0, 1, 2,
		2, 3, 0,

		// Cara derecha
		1, 5, 6,
		6, 2, 1,

		// Cara trasera
		5, 4, 7,
		7, 6, 5,

		// Cara izquierda
		4, 0, 3,
		3, 7, 4,

		// Cara superior
		3, 2, 6,
		6, 7, 3,

		// Cara inferior
		4, 5, 1,
		1, 0, 4
	};

	// Creamos la malla con 24 valores (8 vertices * 3 componentes) y 36 indices
	mesh.CreateMesh(vertices, indices, 24, 36);
}

void Cube::Update(float deltaTime)
{
	// Rotamos el cubo automaticamente en el eje Y
	float velocidad = 50.0f;  // grados por segundo

	// Obtenemos la rotacion actual y la incrementamos
	glm::vec3 currentRotation = GetRotation();
	currentRotation.y += velocidad * deltaTime;

	// Actualizamos la rotacion
	SetRotation(currentRotation.x, currentRotation.y, currentRotation.z);
}
