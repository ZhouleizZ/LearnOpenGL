#include "Render.h"
#include "RawModel.h"
#include "glad/glad.h"

Render::Render()
{
	//glPolygonMode(GL_FRONT_AND_BACK,GL_LINE);
}

void Render::prepare()
{
	//Render
	glClearColor(0.2,0.3,0.3,1.0);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Render::onRender(RawModel*& model)
{
	if (!model)
	{
		return;
	}
	// draw our first triangle
	unsigned int vaoid = model->getVaoID();
	int cnt = model->getVertexCnt();
	glBindVertexArray(vaoid);// seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
	glEnableVertexAttribArray(0); // 开启顶点属性   重要  开启0号位置顶点属性  对应 存储的0号位置
	//glDrawArrays(GL_TRIANGLES,0, cnt);
	glDrawElements(GL_TRIANGLES,model->getVertexCnt(),GL_UNSIGNED_INT,0);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}
