#include"DisplayManager.h"

DisplayManager::DisplayManager()
{

}

void DisplayManager::CreateDisplay()
{
	mDisplay.SetTitle("Open a Window");
	mDisplay.SetDisplayMode(DisplayMode(640,480));
	ContextAttr attr(4,6);
	mDisplay.Create(attr);
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
