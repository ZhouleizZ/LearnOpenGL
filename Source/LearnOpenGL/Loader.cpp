#include "Loader.h"
#include "glad/glad.h"
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"


const char* IMAGE_FILLPATH = "../../Shader/container.jpg";

class RawModel* Loader::loadToVao(float vertices[], int size,unsigned int indexData[],int indexSize)
{
	unsigned int vaoID = createVao();
	bindIndexBuffer(indexData, indexSize);
	storeData2AttriList(0, vertices, size);  //  默认存储的是0号位置  

	unsigned int TextureID = createImageTexture();
	int width = 0, height= 0, nrChannels = 0;
	loadImage(IMAGE_FILLPATH, width, height, nrChannels);
	
	unBindVao();
	RawModel* tmpModel = new RawModel(vaoID, indexSize /(/*3 * */sizeof(int)),TextureID);
	models.push_back(tmpModel);
	return tmpModel;
}

void Loader::cleanUp()
{
	if (vaos.size() > 0)
	{
		glDeleteVertexArrays(vaos.size(),vaos.data());
	}

	if (vbos.size() > 0)
	{
		glDeleteVertexArrays(vbos.size(), vbos.data());
	}

	if (models.size() > 0)
	{
		for (auto it: models)
		{
			delete it;
		}
	}
}

unsigned int Loader::createVao()
{
	//初始化VAO
	unsigned int vaoID;
	glGenVertexArrays(1,&vaoID);
	//绑定VAO
	glBindVertexArray(vaoID);
	vaos.push_back(vaoID);
	return vaoID;
}

void Loader::bindIndexBuffer(unsigned int indexBuffer[], int size)
{
	unsigned int iboID;
	glGenBuffers(1,&iboID);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER,iboID);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER,size,indexBuffer, GL_STATIC_DRAW);
}

void Loader::unBindVao()
{
	glBindVertexArray(0);
}

void Loader::storeData2AttriList(int index, float vertices[], int size)
{
	//把顶点数组复制到缓冲内存中供OpenGL使用
	unsigned int vboID;
	glGenBuffers(1,&vboID);
	glBindBuffer(GL_ARRAY_BUFFER,vboID);
	glBufferData(GL_ARRAY_BUFFER,size, vertices,GL_STATIC_DRAW);
	// 设置顶点属性指针  告诉OpenGL该如何解析顶点数据
	//glVertexAttribPointer(index,3,GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);

	// 位置属性
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);
	// 颜色属性
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(3 * sizeof(float)));
	glEnableVertexAttribArray(1);
	//位置坐标
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(float), (void*)(6 * sizeof(float)));
	glEnableVertexAttribArray(2);

	//glBindBuffer(GL_ARRAY_BUFFER,0);
	vbos.push_back(vboID);

	glEnableVertexAttribArray(0);
}

unsigned int Loader::createImageTexture()
{
	unsigned int texture;
	glGenTextures(1, &texture);   //第一个参数为生成纹理数量
	glBindTexture(GL_TEXTURE_2D, texture);

	// 为当前绑定的纹理对象设置环绕、过滤方式
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	return texture;
}

void Loader::loadImage(char const* imagePath, int w, int h, int ColorChannels)
{
	//使用载入的图片数据生成一个纹理
	unsigned char* data = stbi_load(imagePath, &w, &h, &ColorChannels, 0);
	if (data)
	{
		//当调用glTexImage2D时，当前绑定的纹理对象就会被附加上纹理图像
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(data);
	}
	else
	{
		std::cout << "Failed to load texture" << std::endl;
	}
}

