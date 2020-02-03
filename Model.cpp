#include "Model.h"

Model::Model(Model const& model) {
	m_mesh = model.getMesh();
	m_position = model.getPosition();
	m_size = model.getSize();
	m_texture = model.getTexture();
	m_shader = model.getShader();
}

Model::Model(Mesh* mesh, vec3 position, float size, Rotation* rotation, Texture* texture, Shader* shader) {
	m_mesh = mesh;
	m_position = position;
	m_size = size;
	m_rotation = rotation;
	m_texture = texture;
	m_shader = shader;
}

Model::~Model() {
	delete m_mesh;
	m_mesh = NULL;
	delete m_rotation;
	m_rotation = NULL;
	delete m_shader;
	m_shader = NULL;
	delete m_texture;
	m_texture = NULL;
}

Mesh* Model::getMesh() const {
	return m_mesh;
}

void Model::setMesh(Mesh* mesh) {
	m_mesh = mesh;
}

vec3 Model::getPosition() const {
	return m_position;
}

void Model::setPosition(vec3 position) {
	m_position = position;
}

float Model::getSize() const {
	return m_size;
}

void Model::setSize(float size) {
	m_size = size;
}

Rotation* Model::getRotation() const {
	return m_rotation;
}

void Model::setRotation(Rotation* rotation) {
	m_rotation = rotation;
}

Texture* Model::getTexture() const {
	return m_texture;
}

void Model::setTexture(Texture* texture) {
	m_texture = texture;
}

Shader* Model::getShader() const {
	return m_shader;
}

void Model::setShader(Shader* shader) {
	m_shader = shader;
}