#include "Mesh.h"

Mesh::Mesh()
{
}

void Mesh::CreateMesh(GLfloat* vertices, GLuint* indices, GLuint numVertices, GLsizei numIndices)
{
    indexCount = numIndices;
    glGenVertexArrays(1, &VAO); //Genera y devuelve id
    glBindVertexArray(VAO); //Activa VAO

    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices[0])*numIndices, indices, GL_STATIC_DRAW);

    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);

    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices[0])*numVertices, vertices, GL_STATIC_DRAW);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), 0);
    glEnableVertexAttribArray(0);


    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Mesh::DeleteMesh()
{
    if (VAO != 0) {
        glDeleteVertexArrays(1, &VAO);
        VAO = 0;
    }
    if (EBO != 0) {
        glDeleteBuffers(1, &EBO);
        EBO = 0;
    }
    if (VBO != 0) {
        glDeleteBuffers(1, &VBO);
        VBO = 0;
    }
}

void Mesh::RenderMesh()
{
    glBindVertexArray(VAO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 12, GL_UNSIGNED_INT, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

Mesh::~Mesh()
{
    DeleteMesh();
}
