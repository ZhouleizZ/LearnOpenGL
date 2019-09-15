#pragma once
#include "Display.h"
#include "Enum.h"
class DisplayManager
{
private:
	Display mDisplay;
public:

	DisplayManager();

	void CreateDisplay();
	EMDisplayState UpdateDisplay();
	void DestroyDisplay();
	bool isRequestClose();
};