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
		 0.5f,  0.5f, 0.0f,   1.0f, 0.0f, 0.0f,   1.0f, 1.0f,   // ����
		 0.5f, -0.5f, 0.0f,   0.0f, 1.0f, 0.0f,   1.0f, 0.0f,   // ����
		-0.5f, -0.5f, 0.0f,   0.0f, 0.0f, 1.0f,   0.0f, 0.0f,   // ����
		-0.5f,  0.5f, 0.0f,   1.0f, 1.0f, 0.0f,   0.0f, 1.0f    // ����
	};

	unsigned int indexData[]{// ע��������0��ʼ! 
		0, 1, 3, // ��һ��������
		1, 2, 3  // �ڶ���������
	};


	float texCoords[] = {
		0.0f,0.0f,  //���½�
		1.0f,0.0f,  //���½�
		0.5f,1.0f,  //����
	};


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

