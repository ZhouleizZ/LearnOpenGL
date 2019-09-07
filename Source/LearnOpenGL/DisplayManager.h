#pragma once
#include "Display.h"

class DisplayManager
{
private:
	Display mDisplay;
public:

	DisplayManager();

	void CreateDisplay();
	void UpdateDisplay();
	void DestroyDisplay();
	bool isRequestClose();
};