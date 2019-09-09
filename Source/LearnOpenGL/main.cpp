#include "DisplayManager.h"
#include "Loader.h"
#include "Render.h"
#include "RawModel.h"
int main()
{
	DisplayManager mDisplayManager;
	mDisplayManager.CreateDisplay();

	Loader mLoader;

	float position[] = {
		  -0.5f, -0.5f, 0.0f, // left  
		   0.5f, -0.5f, 0.0f, // right 
		   0.0f,  0.5f, 0.0f  // top   
	};
	RawModel* mModel = mLoader.loadToVao(position,sizeof(position));
	
	Render mRender;

	while (!mDisplayManager.isRequestClose())
	{

		mRender.prepare();
		mRender.onRender(mModel);

		mDisplayManager.UpdateDisplay();
	}

	mLoader.cleanUp();

	mDisplayManager.DestroyDisplay();
	return 0;
}

