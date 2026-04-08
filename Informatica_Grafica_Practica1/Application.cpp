#include "Application.h"
#include <glm/gtc/matrix_transform.hpp>

Application::Application()
	: mainWindow(800, 600)
{
}

Application::~Application()
{
	// Liberamos todos los objetos creados dinamicamente
	for (Object* obj : objectList)
	{
		delete obj;
	}
	objectList.clear();
}

int Application::Initialise()
{
	// 1. Inicializar la ventana
	if (mainWindow.Initialize() != 0)
	{
		printf("Error: No se pudo inicializar la ventana\n");
		return -1;
	}

	// 2. Cargar el shader principal
	mainShader.CreateShadersFromFile("Shaders/shader.vert", "Shaders/shader.frag");

	// 3. Crear la matriz de proyeccion en perspectiva
	projection = glm::perspective(
		glm::radians(45.0f),
		(GLfloat)mainWindow.getBufferWidth() / (GLfloat)mainWindow.getBufferHeight(),
		0.1f,
		100.0f
	);

	// 4. Crear los objetos de la escena
	CreateObjects();

	return 0;
}

void Application::CreateObjects()
{
	// Crear un triangulo
	Triangle* triangle = new Triangle(&mainShader);
	triangle->Init();
	triangle->SetPosition(-1.5f, 0.0f, -6.0f);
	triangle->SetScale(0.8f, 0.8f, 0.8f);
	objectList.push_back(triangle);

	// Crear un cubo
	Cube* cube = new Cube(&mainShader);
	cube->Init();
	cube->SetPosition(1.5f, 0.0f, -7.0f);
	cube->SetScale(0.5f, 0.5f, 0.5f);
	objectList.push_back(cube);
}

void Application::Run()
{
	float lastTime = (float)glfwGetTime();
	float deltaTime;

	// Bucle principal del programa
	while (!mainWindow.getWindowShouldClose())
	{
		// Calcular deltaTime
		float currentTime = (float)glfwGetTime();
		deltaTime = currentTime - lastTime;
		lastTime = currentTime;

		// Procesar eventos (teclado, raton, etc.)
		glfwPollEvents();

		// Limpiar la pantalla
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Actualizar y renderizar todos los objetos
		for (Object* obj : objectList)
		{
			// Actualizar el objeto (animaciones, fisica, etc.)
			obj->Update(deltaTime);

			// Renderizar el objeto
			obj->Render(projection);
		}

		// Intercambiar buffers para mostrar lo renderizado
		mainWindow.swapBuffers();
	}
}