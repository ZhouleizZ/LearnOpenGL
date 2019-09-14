#pragma once
#include "RawModel.h"
#include <vector>
class Loader
{
public:
	class RawModel* loadToVao(float vertices[],int size, unsigned int indexData[], int indexSize);

	void cleanUp();
private:
	unsigned int createVao();

	void bindIndexBuffer(unsigned int indexBuffer[] ,int size);
	void unBindVao();

	void storeData2AttriList(int index,float vertices[],int size);
private:
	std::vector<unsigned int> vaos;
	std::vector<unsigned int> vbos;
	std::vector<class RawModel*> models;
};