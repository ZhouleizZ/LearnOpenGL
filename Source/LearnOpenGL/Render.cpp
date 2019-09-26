#include "Render.h"
#include "RawModel.h"
#include "glad/glad.h"
#include "StaticShader.h"
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

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

	glEnableVertexAttribArray(0); // ������������   ��Ҫ  ����0��λ�ö�������  ��Ӧ �洢��0��λ��
	//glDrawArrays(GL_TRIANGLES,0, cnt);

	glDrawElements(GL_TRIANGLES, model->getVertexCnt(), GL_UNSIGNED_INT, 0);


	glm::vec3 cubePositions[] = {
		glm::vec3(0.0f,  0.0f,  0.0f),
		glm::vec3(2.0f,  5.0f, -15.0f),
		glm::vec3(-1.5f, -2.2f, -2.5f),
		glm::vec3(-3.8f, -2.0f, -12.3f),
		glm::vec3(2.4f, -0.4f, -3.5f),
		glm::vec3(-1.7f,  3.0f, -7.5f),
		glm::vec3(1.3f, -2.0f, -2.5f),
		glm::vec3(1.5f,  2.0f, -2.5f),
		glm::vec3(1.5f,  0.2f, -1.5f),
		glm::vec3(-1.3f,  1.0f, -1.5f)
	};
	for (unsigned int i = 0; i < 10; i++)
	{
		glm::mat4 model_;
		model_ = glm::translate(model_, cubePositions[i]);
		float angle = 20.0f * i;
		model_ = glm::rotate(model_, glm::radians(angle), glm::vec3(1.0f, 0.3f, 0.5f));
		int modelLoc = glGetUniformLocation(shader->getProgramId(), "model");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model_));
		glDrawElements(GL_TRIANGLES, model->getVertexCnt(), GL_UNSIGNED_INT, 0);
	}


	//������������ٽ��VAO��
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);
}
