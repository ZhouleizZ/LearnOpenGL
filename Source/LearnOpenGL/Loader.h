#pragma once
#include "RawModel.h"
#include <vector>



class Loader
{
public:
	class RawModel* loadToVao(float vertices[],int size, unsigned int indexData[], int indexSize);

	void cleanUp();
private:

	//vao
	unsigned int createVao();
	//ibo
	void bindIndexBuffer(unsigned int indexBuffer[] ,int size);
	void unBindVao();
	//vbo
	void storeData2AttriList(int index,float vertices[],int size);

	//image
	unsigned int createImageTexture();
	void loadImage(char const* imagePath,int w, int h, int ColorChannels);
private:
	std::vector<unsigned int> vaos;
	std::vector<unsigned int> vbos;
	std::vector<class RawModel*> models;
};