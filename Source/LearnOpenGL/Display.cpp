#include"Display.h"
#include"GLFW/glfw3.h"
#include "iostream"
void Display::Create(ContextAttr attr)
{
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, attr.major);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, attr.minor);
	if (attr.bProfileCore)
	{
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	}
	mWindow = glfwCreateWindow(mDisplayMode.width, mDisplayMode.height, title, nullptr, nullptr);
	if (!mWindow)
	{
		std::cout << "create window failed." << std::endl;
		return;
	}
	glfwMakeContextCurrent(mWindow);
	
	glfwSetFramebufferSizeCallback(mWindow,&Display::frameBuffSizeCallback);
}

void Display::Update()
{
	processEvent();
	glfwPollEvents();	
	glfwSwapBuffers(mWindow);
}

void Display::destroy()
{
	glfwDestroyWindow(mWindow);
	glfwTerminate();
	mWindow = nullptr;
}

void Display::SetTitle(const char* _title)
{
	title = _title;
}

void Display::SetDisplayMode(DisplayMode mode)
{
	mDisplayMode = mode;
}

void Display::frameBuffSizeCallback(GLFWwindow* _window, int _w, int _h)
{

}

void Display::processEvent()
{
	if (glfwGetKey(mWindow,GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(mWindow,true);
	}
}
