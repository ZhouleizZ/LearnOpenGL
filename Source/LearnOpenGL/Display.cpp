#include"Display.h"
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
	
	//if (!gladLoadGL())
	//{
	//	std::cout << "Failed to initialize GLAD" << std::endl;
	//}
	//load all OpenGL funtion potints
	glfwSetFramebufferSizeCallback(mWindow, &Display::frameBuffSizeCallback);
	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
	{
		std::cout << "Failed to initialize GLAD" << std::endl;
		return;
	}
	

}

EMDisplayState Display::Update()
{
	//检查并调用时间，交换缓冲
	glfwPollEvents();	
	glfwSwapBuffers(mWindow);


	return 	processEvent();
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
	glViewport(0,0,_w,_h);
}

EMDisplayState Display::processEvent()
{
	if (glfwGetKey(mWindow,GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(mWindow,true);
		return EMDisplayState::State_Success;
	}
	else if (glfwGetKey(mWindow, GLFW_KEY_R) == GLFW_PRESS)
	{
		return EMDisplayState::State_Reload;
	}
}
