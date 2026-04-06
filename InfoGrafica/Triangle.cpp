#include "Triangle.h"

Triangle::Triangle(Shader* shader) : Object(shader)
{
}

Triangle::~Triangle()
{
}

void Triangle::Init()
{
	// Definimos los vertices del triangulo (3 vertices)
	// Vertice abajo izquierda, abajo derecha, arriba centro
	GLfloat vertices[] = {
		-1.0f, -1.0f, 0.0f,  // Vertice 0: abajo izquierda
		 1.0f, -1.0f, 0.0f,  // Vertice 1: abajo derecha
		 0.0f,  1.0f, 0.0f   // Vertice 2: arriba centro
	};

	// Definimos los indices (1 triangulo = 3 indices)
	GLuint indices[] = {
		0, 1, 2  // Triangulo formado por los vertices 0, 1, 2
	};

	// Creamos la malla con 9 valores de vertices (3 vertices * 3 componentes)
	// y 3 indices
	mesh.CreateMesh(vertices, indices, 9, 3);
}