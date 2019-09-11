#include "Render.h"
#include "RawModel.h"
#include "glad/glad.h"

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
	glEnableVertexAttribArray(0); // ø™∆Ù∂•µ„ Ù–‘
	glDrawArrays(GL_TRIANGLES,0, cnt);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}
