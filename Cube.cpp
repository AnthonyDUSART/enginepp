#include "Cube.h"

Cube::Cube(float size, vec3 coords, Rotation* rotation, Shader* shader) {
	m_size = size;
	m_coords = coords;
	m_rotation = rotation;
	m_shader = shader;
	float vertices[] = { 
		-m_size, -m_size, -m_size,   m_size, -m_size, -m_size,   m_size,  m_size, -m_size, // Face 1
		-m_size, -m_size, -m_size,  -m_size,  m_size, -m_size,   m_size,  m_size, -m_size, // Face 1

		 m_size, -m_size,  m_size,   m_size, -m_size, -m_size,   m_size,  m_size, -m_size, // Face 2
		 m_size, -m_size,  m_size,   m_size,  m_size,  m_size,   m_size,  m_size, -m_size, // Face 2

		-m_size, -m_size,  m_size,   m_size, -m_size,  m_size,   m_size, -m_size, -m_size, // Face 3
		-m_size, -m_size,  m_size,  -m_size, -m_size, -m_size,   m_size, -m_size, -m_size, // Face 3

		-m_size, -m_size,  m_size,	 m_size, -m_size,  m_size,   m_size,  m_size,  m_size, // Face 4
		 m_size,  m_size,  m_size,  -m_size,  m_size,  m_size,  -m_size, -m_size,  m_size, // Face 4

		-m_size, -m_size,  m_size,  -m_size, -m_size, -m_size,  -m_size,  m_size, -m_size, // Face 5
		-m_size,  m_size,- m_size,  -m_size,  m_size,  m_size,  -m_size, -m_size,  m_size, // Face 5

		-m_size,  m_size,  m_size,   m_size,  m_size,  m_size,   m_size,  m_size, -m_size, // Face 6
		 m_size,  m_size, -m_size,  -m_size,  m_size, -m_size,  -m_size,  m_size,  m_size  // Face 6

	};

	float colors[] = {
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0, // Face 1
		1.0, 0.0, 0.0,   1.0, 0.0, 0.0,   1.0, 0.0, 0.0, // Face 1

		0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0, // Face 2
		0.0, 1.0, 0.0,   0.0, 1.0, 0.0,   0.0, 1.0, 0.0, // Face 2

		0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0, // Face 3
		0.0, 0.0, 1.0,   0.0, 0.0, 1.0,   0.0, 0.0, 1.0, // Face 3

		1.0, 1.0, 0.0,   1.0, 1.0, 0.0,   1.0, 1.0, 0.0, // Face 4
		1.0, 1.0, 0.0,   1.0, 1.0, 0.0,   1.0, 1.0, 0.0, // Face 4

		0.0, 1.0, 1.0,   0.0, 1.0, 1.0,   0.0, 1.0, 1.0, // Face 5
		0.0, 1.0, 1.0,   0.0, 1.0, 1.0,   0.0, 1.0, 1.0, // Face 5

		1.0, 0.0, 1.0,   1.0, 0.0, 1.0,   1.0, 0.0, 1.0, // Face 6
		1.0, 0.0, 1.0,   1.0, 0.0, 1.0,   1.0, 0.0, 1.0  // Face 6 
	};

	for (unsigned int i = 0; i < 108; i++) {
		m_vertices[i] = vertices[i];
		m_colors[i] = colors[i];
	}
}

Cube::~Cube() {
	delete m_rotation;
}

void Cube::show(glm::mat4& projection, glm::mat4& modelview) {

	m_shader->charger();
	// sauvegarde du modelview
	mat4 modelviewSave = modelview;

	// modification du modelview
	modelview = translate(modelview, m_coords);
	modelview = rotate(modelview, m_rotation->getAngle(), m_rotation->getAxis());

	glUseProgram(m_shader->getProgramID());


	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, m_vertices);
	glEnableVertexAttribArray(0);

	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, m_colors);
	glEnableVertexAttribArray(1);

	// envoi des matrices au shader
	glUniformMatrix4fv(glGetUniformLocation(m_shader->getProgramID(), "projection"), 1, GL_FALSE, value_ptr(projection));
	glUniformMatrix4fv(glGetUniformLocation(m_shader->getProgramID(), "modelview"), 1, GL_FALSE, value_ptr(modelview));

	// dessine les vertices
	glDrawArrays(GL_TRIANGLES, 0, 36);

	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);

	glUseProgram(0);

	// restauration du modelview
	modelview = modelviewSave;

}

Shader* Cube::getShader() const {
	return m_shader;
}

void Cube::setShader(Shader* shader) {
	m_shader = shader;
}

float Cube::getSize() const {
	return m_size;
}

void Cube::setSize(float size) {
	m_size = size;
}

vec3 Cube::getCoords() const {
	return m_coords;
}

void Cube::setCoords(vec3 coords) {
	m_coords = coords;
}

Rotation* Cube::getRotation() const {
	return m_rotation;
}

void Cube::setRotation(Rotation* rotation) {
	m_rotation = rotation;
}