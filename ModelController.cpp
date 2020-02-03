#include "ModelController.h"

void ModelController::load(Model* model) {
	MeshController::load(model->getMesh());
	model->getTexture()->load();
	model->getShader()->charger();
	
}

void ModelController::render(Model* model, mat4& projection, mat4& modelview) {
	//model->getShader()->charger();

	// sauvegarde du modelview
	mat4 modelviewSave = modelview;

	// modification du modelview
	modelview = translate(modelview, model->getPosition());
	modelview = rotate(modelview, model->getRotation()->getAngle(), model->getRotation()->getAxis());

	glUseProgram(model->getShader()->getProgramID());

	glBindBuffer(GL_ARRAY_BUFFER, model->getMesh()->getVboId());

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(model->getMesh()->getVerticesBytes()));
	glEnableVertexAttribArray(2);

	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glUniformMatrix4fv(glGetUniformLocation(model->getShader()->getProgramID(), "projection"), 1, GL_FALSE, value_ptr(projection));
	glUniformMatrix4fv(glGetUniformLocation(model->getShader()->getProgramID(), "modelview"), 1, GL_FALSE, value_ptr(modelview));

	glBindTexture(GL_TEXTURE_2D, model->getTexture()->getId());
	glDrawArrays(GL_TRIANGLES, 0, model->getMesh()->getVertices().size());
	glBindTexture(GL_TEXTURE_2D, 0);

	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(1);

	glUseProgram(0);

	modelview = modelviewSave;
}