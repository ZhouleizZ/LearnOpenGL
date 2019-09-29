#include"DisplayManager.h"



float lastX = 640 / 2.0f;
float lastY = 480 / 2.0f;
bool firstMouse = true;
// camera
extern Camera mCamera ;

DisplayManager::DisplayManager()
{

}

void DisplayManager::CreateDisplay()
{
	mDisplay.SetTitle("Open a Window");
	mDisplay.SetDisplayMode(DisplayMode(640,480));
	ContextAttr attr(4,6);
	mDisplay.Create(attr);
	bindInput();
}

EMDisplayState DisplayManager::UpdateDisplay()
{
	return mDisplay.Update();
}

void DisplayManager::DestroyDisplay()
{
	mDisplay.destroy();
}

bool DisplayManager::isRequestClose()
{
	return glfwWindowShouldClose(mDisplay.mWindow);
}

void DisplayManager::bindInput()
{
	//load all OpenGL funtion potints
	glfwSetCursorPosCallback(mDisplay.mWindow, mouseCallback);
	glfwSetScrollCallback(mDisplay.mWindow, scrollCallback);
	// tell GLFW to capture our mouse
	glfwSetInputMode(mDisplay.mWindow, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
}

void DisplayManager::processInput(GLFWwindow* window, float deltaTime)
{
	if (glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS)
		mCamera.ProcessKeyboard(FORWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS)
		mCamera.ProcessKeyboard(BACKWARD, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS)
		mCamera.ProcessKeyboard(LEFT, deltaTime);
	if (glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS)
		mCamera.ProcessKeyboard(RIGHT, deltaTime);
}

void mouseCallback(GLFWwindow* window, double xpos, double ypos)
{
	if (firstMouse)
	{
		lastX = xpos;
		lastY = ypos;
		firstMouse = false;
	}

	float xoffset = xpos - lastX;
	float yoffset = lastY - ypos; // reversed since y-coordinates go from bottom to top

	lastX = xpos;
	lastY = ypos;
	mCamera.ProcessMouseMovement(xoffset, yoffset);
}

void scrollCallback(GLFWwindow* window, double xoffset, double yoffset)
{
	mCamera.ProcessMouseScroll(yoffset);
}