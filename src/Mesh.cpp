#include "Mesh.h"

Mesh::Mesh(GLuint vboId, std::vector<glm::vec3> vertices, std::vector<glm::vec2> textureCoords, std::vector<glm::vec3> normals, int verticesBytes, int textureCoordsBytes, int normalsBytes) {
	m_vboId = vboId;
	m_vertices = vertices;
	m_textureCoords = textureCoords;
	m_normals = normals;
	m_verticesBytes = verticesBytes;
	m_textureCoordsBytes = textureCoordsBytes;
	m_normalsBytes = normalsBytes;
}

Mesh::~Mesh() {
	glDeleteBuffers(1, &m_vboId);
}

GLuint& Mesh::vboId() {
	return m_vboId;
}
GLuint Mesh::getVboId() const {
	return m_vboId;
}

void Mesh::setVboId(GLuint vboId) {
	m_vboId = vboId;
}

std::vector<glm::vec3> Mesh::getVertices() const {
	return m_vertices;
}

void Mesh::setVertices(std::vector<glm::vec3> vertices) {
	m_vertices = vertices;
}

void Mesh::addVertex(glm::vec3 vertex) {
	m_vertices.push_back(vertex);
}

std::vector<glm::vec2> Mesh::getTextureCoords() const {
	return m_textureCoords;
}

void Mesh::setTextureCoords(std::vector<glm::vec2> textureCoords) {
	m_textureCoords = textureCoords;
}

void Mesh::addTextureCoord(glm::vec2 textureCoord) {
	m_textureCoords.push_back(textureCoord);
}

std::vector<glm::vec3> Mesh::getNormals() const {
	return m_normals;
}

void Mesh::setNormals(std::vector<glm::vec3> normals) {
	m_normals = normals;
}

void Mesh::addNormal(glm::vec3 normal) {
	m_normals.push_back(normal);
}

int Mesh::getVerticesBytes() const {
	return m_verticesBytes;
}

void Mesh::setVerticesBytes(int verticesBytes) {
	m_verticesBytes = verticesBytes;
}

int Mesh::getTextureCoordsBytes() const {
	return m_textureCoordsBytes;
}

void Mesh::setTextureCoordsBytes(int textureCoordsBytes) {
	m_textureCoordsBytes = textureCoordsBytes;
}

int Mesh::getNormalsBytes() const {
	return m_normalsBytes;
}

void Mesh::setNormalsBytes(int normalsBytes) {
	m_normalsBytes = normalsBytes;
}