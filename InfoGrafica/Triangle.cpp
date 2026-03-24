#include "Triangle.h"

Triangle::Triangle(Shader* shader)
{
	Init();
}

Triangle::~Triangle()
{
}

void Triangle::Init()
{
    GLfloat vertices[] = {
        -1.0f, -1.0f, 0.0f,
        0.0f, -1.0f, -1.0f,
        1.0f, -1.0f, 0.0f,
        0.0f, 1.0f, 0.0f
    };
    GLuint indices[] = {
        0, 3, 1,
        1, 3, 2,
        2, 3, 0,
        0, 2 ,1
    };
    Mesh* newMesh = new Mesh();
    newMesh->CreateMesh(vertices, indices, 12, 12);
}
