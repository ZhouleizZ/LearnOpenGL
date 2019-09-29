#include "DisplayManager.h"
#include "Loader.h"
#include "Render.h"
#include "RawModel.h"
#include "StaticShader.h"
#include "Camera.h"

const char* VERTEX_SHADER_FILLPATH = "../../Shader/vertexShader.vs";
const char* FRAGMENT_SHADER_FILLPATH = "../../Shader/fragmentShader.fs";

const char* IMAGE1_FILLPATH = "../../Shader/container.jpg";
const char* IMAGE2_FILLPATH = "../../Shader/awesomeface.png";

Camera mCamera = glm::vec3(0.0f, 0.0f, 3.0f);

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
		// 0.5f, 0.5f, 0.0f,    0.0f, 0.0f, 1.0f, // 右上角
		// 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,// 右下角
		// -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,// 左下角
		//-0.5f, 0.5f, 0.0f,    1.0f, 0.0f, 1.0f // 左上角


		// 位置              // 颜色
		// 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // 右下
		//-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // 左下
		// 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // 顶部

		//     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
		// 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // 右上
		// 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // 右下
		//-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // 左下
		//-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // 左上


		#pragma region CubePosition
		//     ---- 位置 ----       ---- 颜色 ----     - 纹理坐标 -
		- 0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,		 0.0f, 0.0f,  //左下
		 0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,		1.0f, 0.0f,   //右下
		 0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 1.0f,		1.0f, 1.0f,	  //右上
		 0.5f,  0.5f, -0.5f,	1.0f, 1.0f, 0.0f,		1.0f, 1.0f,   
		-0.5f,  0.5f, -0.5f,	1.0f, 0.0f, 0.0f,		0.0f, 1.0f,		//左上
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,		0.0f, 0.0f,
								
		-0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,	0.0f, 1.0f, 0.0f,		1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 1.0f,		1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,	1.0f, 1.0f, 0.0f,		1.0f, 1.0f,
		-0.5f,  0.5f,  0.5f,	1.0f, 0.0f, 0.0f,		0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,	0.0f, 1.0f, 0.0f,		0.0f, 0.0f,

		-0.5f,  0.5f,  0.5f,	1.0f, 0.0f, 0.0f,		1.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f,		1.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 1.0f,		0.0f, 1.0f,
		-0.5f, -0.5f, -0.5f,	1.0f, 1.0f, 0.0f,		0.0f, 1.0f,
		-0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,		1.0f, 0.0f,

		 0.5f,  0.5f,  0.5f,	1.0f, 0.0f, 0.0f,		1.0f, 0.0f,
		 0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f,		1.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,	0.0f, 0.0f, 1.0f,		0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,	1.0f, 1.0f, 0.0f,		0.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,	0.0f, 1.0f, 0.0f,		1.0f, 0.0f,

		-0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,		0.0f, 1.0f,
		 0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,		1.0f, 1.0f,
		 0.5f, -0.5f,  0.5f,	0.0f, 0.0f, 1.0f,		1.0f, 0.0f,
		 0.5f, -0.5f,  0.5f,	1.0f, 1.0f, 0.0f,		1.0f, 0.0f,
		-0.5f, -0.5f,  0.5f,	1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
		-0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,		0.0f, 1.0f,

		-0.5f,  0.5f, -0.5f,	1.0f, 0.0f, 0.0f,		0.0f, 1.0f,
		 0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f,		1.0f, 1.0f,
		 0.5f,  0.5f,  0.5f,	0.0f, 0.0f, 1.0f,		1.0f, 0.0f,
		 0.5f,  0.5f,  0.5f,	1.0f, 1.0f, 0.0f,		1.0f, 0.0f,
		-0.5f,  0.5f,  0.5f,	1.0f, 0.0f, 0.0f,		0.0f, 0.0f,
		-0.5f,  0.5f, -0.5f,	0.0f, 1.0f, 0.0f,		0.0f, 1.0f
		#pragma endregion
	};

	unsigned int indexData[]{// 注意索引从0开始! 
		//0, 1, 3, // 第一个三角形
		//1, 2, 3  // 第二个三角形
		#pragma region CubeIndex
		0, 1, 2,
		0, 2, 4,

		6, 7, 8,
		6, 8, 10,
		   
		12, 13, 14,
		12, 14, 16,
			    
		18, 19, 20,
		18, 20, 22,
			    
		24, 25, 26,
		24, 26, 28,
			    
		30, 31, 32,
		30, 32, 34,
#pragma endregion
	};

	RawModel* mModel = mLoader.loadToVao(position, sizeof(position),indexData,sizeof(indexData));

	Render mRender;

	StaticShader mShader;

	EMDisplayState mDisplayState;

	// timing
	float deltaTime = 0.0f;	// time between current frame and last frame
	float lastFrame = 0.0f;

	while (!mDisplayManager.isRequestClose())
	{
		// per-frame time logic
		// --------------------
		float currentFrame = glfwGetTime();
		deltaTime = currentFrame - lastFrame;
		lastFrame = currentFrame;
		
		mDisplayManager.processInput(mDisplayManager.mDisplay.mWindow, deltaTime);

		mRender.prepare();
		
		mShader.Start();
	
		mRender.onRender(mModel,&mShader);

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

