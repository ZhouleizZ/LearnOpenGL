#pragma once
#include"GLFW/glfw3.h"
struct DisplayMode
{
	DisplayMode() :width(0), height(0) {}
	DisplayMode(int w, int h) : width(w), height(h) {}

	int width;
	int height;
};

struct ContextAttr
{
	int major;
	int minor;
	bool bProfileCore;
	ContextAttr() :major(0), minor(0), bProfileCore(false) {}
	ContextAttr(int _major,int _minjor) :major(_major), minor(_minjor), bProfileCore(false) {}

	void withProfileCore(bool bUseCore)
	{
		bProfileCore = bUseCore;
	}
};

class Display
{
private:
	DisplayMode mDisplayMode;
	const char* title;
public:
	GLFWwindow* mWindow;
public:
	Display() :title("") , mWindow(nullptr){}
	void Create(ContextAttr attr);
	void Update();
	void destroy();

	void SetTitle(const char* _title);
	void SetDisplayMode(DisplayMode mode);
	static void frameBuffSizeCallback(GLFWwindow* _window, int _w, int _h);

private:
	void processEvent();
};