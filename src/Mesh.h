#pragma once

#ifdef _WIN32
#include <GL/glew.h>

#elif __linux__
#define GL3_PROTOTYPES 1
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#endif // _WIN32

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <vector>

class Mesh
{
public:
	Mesh(GLuint vboId = 0, std::vector<glm::vec3> vertices = std::vector<glm::vec3>(), std::vector<glm::vec2> textureCoords = std::vector<glm::vec2>(), std::vector<glm::vec3> normals = std::vector<glm::vec3>(), int verticesBytes = 0, int textureCoordsBytes = 0, int normalsBytes = 0);
	~Mesh();
	GLuint& vboId();
	GLuint getVboId() const;
	void setVboId(GLuint vboId);
	std::vector<glm::vec3> getVertices() const;
	void setVertices(std::vector<glm::vec3> vertices);
	void addVertex(glm::vec3 vertex);
	std::vector<glm::vec2> getTextureCoords() const;
	void setTextureCoords(std::vector<glm::vec2> textureCoords);
	void addTextureCoord(glm::vec2 textureCoord);
	std::vector<glm::vec3> getNormals() const;
	void setNormals(std::vector<glm::vec3> normals);
	void addNormal(glm::vec3 normal);
	int getVerticesBytes() const;
	void setVerticesBytes(int verticesBytes);
	int getTextureCoordsBytes() const;
	void setTextureCoordsBytes(int textureCoordsBytes);
	int getNormalsBytes() const;
	void setNormalsBytes(int normalsBytes);

private:
	GLuint m_vboId;
	std::vector<glm::vec3> m_vertices;
	std::vector<glm::vec2> m_textureCoords;
	std::vector<glm::vec3> m_normals;
	int m_verticesBytes;
	int m_textureCoordsBytes;
	int m_normalsBytes;
};

