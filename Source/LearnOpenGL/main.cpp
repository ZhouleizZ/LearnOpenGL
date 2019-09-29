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
		//// ��һ��������
		//0.5f, 0.5f, 0.0f,   // ���Ͻ�
		//0.5f, -0.5f, 0.0f,  // ���½�
		//-0.5f, 0.5f, 0.0f,  // ���Ͻ�
		//// �ڶ���������
		//0.5f, -0.5f, 0.0f,  // ���½�
		//-0.5f, -0.5f, 0.0f, // ���½�
		//-0.5f, 0.5f, 0.0f   // ���Ͻ� 

		////  ������
		// 0.5f, 0.5f, 0.0f,    0.0f, 0.0f, 1.0f, // ���Ͻ�
		// 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,// ���½�
		// -0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,// ���½�
		//-0.5f, 0.5f, 0.0f,    1.0f, 0.0f, 1.0f // ���Ͻ�


		// λ��              // ��ɫ
		// 0.5f, -0.5f, 0.0f,  1.0f, 0.0f, 0.0f,   // ����
		//-0.5f, -0.5f, 0.0f,  0.0f, 1.0f, 0.0f,   // ����
		// 0.0f,  0.5f, 0.0f,  0.0f, 0.0f, 1.0f    // ����

		//     ---- λ�� ----       ---- ��ɫ ----     - �������� -
		// 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // ����
		// 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // ����
		//-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // ����
		//-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // ����


		#pragma region CubePosition
		//     ---- λ�� ----       ---- ��ɫ ----     - �������� -
		- 0.5f, -0.5f, -0.5f,	1.0f, 0.0f, 0.0f,		 0.0f, 0.0f,  //����
		 0.5f, -0.5f, -0.5f,	0.0f, 1.0f, 0.0f,		1.0f, 0.0f,   //����
		 0.5f,  0.5f, -0.5f,	0.0f, 0.0f, 1.0f,		1.0f, 1.0f,	  //����
		 0.5f,  0.5f, -0.5f,	1.0f, 1.0f, 0.0f,		1.0f, 1.0f,   
		-0.5f,  0.5f, -0.5f,	1.0f, 0.0f, 0.0f,		0.0f, 1.0f,		//����
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

	unsigned int indexData[]{// ע��������0��ʼ! 
		//0, 1, 3, // ��һ��������
		//1, 2, 3  // �ڶ���������
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

