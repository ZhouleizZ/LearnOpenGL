#include "DisplayManager.h"
#include "Loader.h"
#include "Render.h"
#include "RawModel.h"
#include "StaticShader.h"


int main()
{
	DisplayManager mDisplayManager;
	mDisplayManager.CreateDisplay();

	Loader mLoader;

	float position[] = {
		//// 第一个三角形
		//0.5f, 0.5f, 0.0f,   // 右上角
		//0.5f, -0.5f, 0.0f,  // 右下角
		//-0.5f, 0.5f, 0.0f,  // 左上角
		//// 第二个三角形
		//0.5f, -0.5f, 0.0f,  // 右下角
		//-0.5f, -0.5f, 0.0f, // 左下角
		//-0.5f, 0.5f, 0.0f   // 左上角 

		////  正方形
		// 0.5f, 0.5f, 0.0f,   // 右上角
		// 0.5f, -0.5f, 0.0f,  // 右下角
		// -0.5f, -0.5f, 0.0f, // 左下角
		//-0.5f, 0.5f, 0.0f   // 左上角


		// 位置              // 颜色
		 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
		-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
		 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部
	};

	unsigned int indexData[]{// 注意索引从0开始! 
		0, 1, 2/*3*/, // 第一个三角形
		//1, 2, 3  // 第二个三角形
	};
	//RawModel* mModel = mLoader.loadToVao(position,sizeof(position));
	
	RawModel* mModel = mLoader.loadToVao(position, sizeof(position),indexData,sizeof(indexData));

	Render mRender;

	StaticShader mShader;

	EMDisplayState mDisplayState;

	while (!mDisplayManager.isRequestClose())
	{

		mRender.prepare();
		
		
		mShader.Start();
		mRender.onRender(mModel);
		mShader.Stop();

		mDisplayState = mDisplayManager.UpdateDisplay();
		if (mDisplayState == EMDisplayState::State_Reload)
		{
			mShader.reloadShader();
		}
	}

	mShader.CleanUp();
	mLoader.cleanUp();

	mDisplayManager.DestroyDisplay();
	return 0;
}

