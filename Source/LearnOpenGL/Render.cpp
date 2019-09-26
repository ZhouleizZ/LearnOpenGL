#include "Render.h"
#include "RawModel.h"
#include "glad/glad.h"
#include "StaticShader.h"

Render::Render()
{
	//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);

	// configure global opengl state
	// -----------------------------
	glEnable(GL_DEPTH_TEST);
}

void Render::prepare()
{
	//Render
	glClearColor(0.2,0.3,0.3,1.0);
	//glClear(GL_COLOR_BUFFER_BIT);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // also clear the depth buffer now!
}

void Render::onRender(RawModel*& model, StaticShader* shader)
{
	if (!model)
	{
		return;
	}
	// draw our first triangle
	unsigned int vaoid = model->getVaoID();
	int cnt = model->getVertexCnt();
	glBindVertexArray(vaoid);// seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized

	// bind textures on corresponding texture units
	glActiveTexture(GL_TEXTURE0);
	glBindTexture(GL_TEXTURE_2D, model->getTextureID());
	glActiveTexture(GL_TEXTURE1);
	glBindTexture(GL_TEXTURE_2D, model->getTexture2ID());

	glEnableVertexAttribArray(0); // 开启顶点属性   重要  开启0号位置顶点属性  对应 存储的0号位置
	//glDrawArrays(GL_TRIANGLES,0, cnt);

	glDrawElements(GL_TRIANGLES, model->getVertexCnt(), GL_UNSIGNED_INT, 0);

	for (unsigned int i = 0; i < 10; i++)
	{
		shader->setUniform_Modelmat4(cubePositions[i],i);
		glDrawElements(GL_TRIANGLES, model->getVertexCnt(), GL_UNSIGNED_INT, 0);
	}


	//绘制完物体后，再解绑VAO。
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}
