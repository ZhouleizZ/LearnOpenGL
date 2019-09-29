#pragma once
#include "Display.h"
#include "Enum.h"
#include "Camera.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>


// glfw: whenever the mouse moves, this callback is called
// -------------------------------------------------------
static void mouseCallback(GLFWwindow* window, double xpos, double ypos);
// glfw: whenever the mouse scroll wheel scrolls, this callback is called
// ----------------------------------------------------------------------
static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

class DisplayManager
{
private:
	
public:

	DisplayManager();
	Display mDisplay;

	void CreateDisplay();
	EMDisplayState UpdateDisplay();
	void DestroyDisplay();
	bool isRequestClose();

	void bindInput();
	void processInput(GLFWwindow* window, float deltaTime);
};