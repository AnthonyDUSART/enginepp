#include "TexturedCube.h"

TexturedCube::TexturedCube(float size, vec3 coords, Rotation* rotation, Texture* texture, TextureShader* shader) : Cube(size, coords, rotation, shader)
{
	m_texture = texture;
	m_texture->load();
	float textureCoords[] = {
		0, 0,	1, 0,	2, 1, // Face 1
		0, 0,	0, 1,	1, 1, // Face 1

		0, 0,	1, 0,	1, 1, // Face 2
		0, 0,	0, 1,	1, 1, // Face 2

		0, 0,	1, 0,	1, 1, // Face 3
		0, 0,	0, 1,	1, 1, // Face 3

		0, 0,	1, 0,	1, 1, // Face 4
		0, 0,	0, 1,	1, 1, // Face 4

		0, 0,	1, 0,	1, 1, // Face 5
		0, 0,	0, 1,	1, 1, // Face 5

		0, 0,	1, 0,	1, 1, // Face 6
		0, 0,	0, 1,	1, 1, // Face 6
	};

	for (unsigned int i = 0; i < 72; i++) {
		m_textureCoords[i] = textureCoords[i];
	}
}

TexturedCube::~TexturedCube() {
}

void TexturedCube::show(glm::mat4& projection, glm::mat4& modelview)
{
	mat4 modelviewSave = modelview;

	// modification du modelview
	modelview = translate(modelview, m_coords);
	modelview = rotate(modelview, m_rotation->getAngle(), m_rotation->getAxis());

	glUseProgram(m_shader->getProgramID());

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, m_vertices);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, m_textureCoords);
	glEnableVertexAttribArray(2);

	glUniformMatrix4fv(glGetUniformLocation(m_shader->getProgramID(), "projection"), 1, GL_FALSE, value_ptr(projection));
	glUniformMatrix4fv(glGetUniformLocation(m_shader->getProgramID(), "modelview"), 1, GL_FALSE, value_ptr(modelview));

	glBindTexture(GL_TEXTURE_2D, m_texture->getId());
	glDrawArrays(GL_TRIANGLES, 0, 36);
	glBindTexture(GL_TEXTURE_2D, 0);

	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(0);
	glUseProgram(0);

	modelview = modelviewSave;
}

Texture* TexturedCube::getTexture() const {
	return m_texture;
}

void TexturedCube::setTexture(Texture* texture) {
	m_texture = texture;
}

