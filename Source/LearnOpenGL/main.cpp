#include "DisplayManager.h"

int main()
{
	DisplayManager mDisplayManager;
	mDisplayManager.CreateDisplay();
	while (!mDisplayManager.isRequestClose())
	{
		mDisplayManager.UpdateDisplay();
	}

	mDisplayManager.DestroyDisplay();
	return 0;
}

