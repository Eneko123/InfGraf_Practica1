#define _USE_MATH_DEFINES

#include <iostream>
#include <cmath>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Mesh.h"
#include "Shader.h"
#include "Window.h"

const GLint WIDTH = 800, HEIGHT = 600;
const float TORADIANS = M_PI / 180.0f;

std::vector<Mesh*> meshList;
std::vector<Shader*> shaderList;

// Vertex shader
static const char* vShader = "Shaders/shader.vert";
// Fragment shader
static const char* fShader = "Shaders/shader.frag";

void CreateTriangle() {
    // Triangulo simple con 3 vertices
    GLfloat vertices[] = {
        -1.0f, -1.0f, 0.0f,  // Vertice 0: abajo izquierda
         1.0f, -1.0f, 0.0f,  // Vertice 1: abajo derecha
         0.0f,  1.0f, 0.0f   // Vertice 2: arriba centro
    };

    GLuint indices[] = {
        0, 1, 2  // Un solo triangulo
    };

    Mesh* newMesh = new Mesh();
    newMesh->CreateMesh(vertices, indices, 9, 3);  // 3 vertices x 3 componentes = 9, 3 indices
    meshList.push_back(newMesh);
}

void CreateCube() {
    // 8 vertices del cubo (x, y, z)
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

    // 36 indices (6 caras x 2 triangulos x 3 vertices)
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

    Mesh* newMesh = new Mesh();
    newMesh->CreateMesh(vertices, indices, 24, 36);  // 8 vertices x 3 componentes = 24, 36 indices
    meshList.push_back(newMesh);
}

void CreateShader() {
    Shader* shader = new Shader();
    shader->CreateShadersFromFile(vShader, fShader);
    shaderList.push_back(shader);
}

int main()
{
    Window mainWindow = Window(WIDTH, HEIGHT);
    mainWindow.Initialize();

    // Habilitar depth test para ver objetos 3D correctamente
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);

    CreateShader();
    CreateTriangle();  // meshList[0] = triangulo
    CreateCube();      // meshList[1] = cubo

    // Crear matriz de proyeccion en perspectiva
    glm::mat4 projection = glm::perspective(
        glm::radians(45.0f),
        (GLfloat)mainWindow.getBufferWidth() / (GLfloat)mainWindow.getBufferHeight(),
        0.1f,
        100.0f
    );

    float lastTime = (float)glfwGetTime();
    float deltaTime;
    float rotation = 0.0f;

    // Bucle principal
    while (!mainWindow.getWindowShouldClose()) {

        glfwPollEvents();

        // Calcular deltaTime
        float currentTime = (float)glfwGetTime();
        deltaTime = currentTime - lastTime;
        lastTime = currentTime;

        // Actualizar rotacion del cubo
        rotation += 50.0f * deltaTime;  // 50 grados por segundo

        // Limpiar pantalla
        glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        // Activar shader
        shaderList[0]->useShader();

        // Dibujar triangulo
        glm::mat4 modelTriangle(1.0f);
        modelTriangle = glm::translate(modelTriangle, glm::vec3(-1.5f, 0.0f, -6.0f));  // Izquierda
        modelTriangle = glm::scale(modelTriangle, glm::vec3(0.8f, 0.8f, 0.8f));        // Escala

        // Enviar matrices al shader
        glUniformMatrix4fv(shaderList[0]->GetIdModel(), 1, GL_FALSE, glm::value_ptr(modelTriangle));
        glUniformMatrix4fv(shaderList[0]->GetIdProjection(), 1, GL_FALSE, glm::value_ptr(projection));

        // Renderizar triangulo
        meshList[0]->RenderMesh();

        // Dibujar cubo
        glm::mat4 modelCube(1.0f);
        modelCube = glm::translate(modelCube, glm::vec3(1.5f, 0.0f, -7.0f));           // Derecha
        modelCube = glm::rotate(modelCube, glm::radians(rotation), glm::vec3(0.0f, 1.0f, 0.0f));  // Rotar en Y
        modelCube = glm::scale(modelCube, glm::vec3(0.5f, 0.5f, 0.5f));                // Escala

        // Enviar matrices al shader
        glUniformMatrix4fv(shaderList[0]->GetIdModel(), 1, GL_FALSE, glm::value_ptr(modelCube));
        glUniformMatrix4fv(shaderList[0]->GetIdProjection(), 1, GL_FALSE, glm::value_ptr(projection));

        // Renderizar cubo
        meshList[1]->RenderMesh();

        glUseProgram(0);
        mainWindow.swapBuffers();
    }

    // Liberar recursos
    for (Mesh* mesh : meshList) {
        delete mesh;
    }
    meshList.clear();

    for (Shader* shader : shaderList) {
        delete shader;
    }
    shaderList.clear();

    return 0;
}
