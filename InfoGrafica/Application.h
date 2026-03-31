#pragma once

#include <iostream>
#include <vector>

#include "Object.h"
#include "Shader.h"
#include "Window.h"

class Application : Object
{
public:

private:
	Window mainWindow;
	Shader mainShader;
	std::vector<Object*> objectList;
	glm::mat4 projection;
};