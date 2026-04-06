#pragma once

#include <iostream>
#include <vector>

#include "Object.h"
#include "Shader.h"
#include "Window.h"
#include "Triangle.h"
#include "Cube.h"

class Application
{
public:
	Application();
	~Application();

	int Initialise();
	void Run();

private:
	void CreateObjects();

	Window mainWindow;
	Shader mainShader;
	std::vector<Object*> objectList;
	glm::mat4 projection;
};
