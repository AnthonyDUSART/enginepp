#include "ModelController.h"

void ModelController::load(Model* model) {
	MeshController::load(model->getMesh());
	model->getTexture()->load();
	model->getShader()->charger();
	
	// eviter la fuite de mémoire
	if (glIsVertexArray(model->getVaoId()) == GL_TRUE)
		glDeleteVertexArrays(1, &model->vaoId());

	glGenVertexArrays(1, &model->vaoId());

	// VAO : Enregistre les appels fonctions vbo dans la VRAM
	glBindVertexArray(model->getVaoId());

		// VBO : Enregistre les données dans la VRAM
		glBindBuffer(GL_ARRAY_BUFFER, model->getMesh()->getVboId());

		// enregistrement données : vertices
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(0));
		glEnableVertexAttribArray(0);

		// enregistrement données : texture coords
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, BUFFER_OFFSET(model->getMesh()->getVerticesBytes()));
		glEnableVertexAttribArray(2);

		glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);
}

void ModelController::render(Model* model, mat4& projection, mat4& modelview) {
	//model->getShader()->charger();

	// sauvegarde du modelview
	mat4 modelviewSave = modelview;

	// modification du modelview
	modelview = translate(modelview, model->getPosition());
	modelview = rotate(modelview, model->getRotation()->getAngle(), model->getRotation()->getAxis());

	glUseProgram(model->getShader()->getProgramID());

	// Verouillage VAO
	glBindVertexArray(model->getVaoId());

		glUniformMatrix4fv(glGetUniformLocation(model->getShader()->getProgramID(), "projection"), 1, GL_FALSE, value_ptr(projection));
		glUniformMatrix4fv(glGetUniformLocation(model->getShader()->getProgramID(), "modelview"), 1, GL_FALSE, value_ptr(modelview));

		glBindTexture(GL_TEXTURE_2D, model->getTexture()->getId());
		glDrawArrays(GL_TRIANGLES, 0, model->getMesh()->getVertices().size());
		glBindTexture(GL_TEXTURE_2D, 0);

	glBindVertexArray(0);

	glUseProgram(0);

	modelview = modelviewSave;
}