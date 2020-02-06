#pragma once

#ifdef _WIN32
#include <GL/glew.h>

#elif __linux__
#define GL3_PROTOTYPES 1
#include <GL3/gl3.h>
#endif // _WIN32

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <vector>
#include "Mesh.h"
#include "Rotation.h"
#include "Texture.h"
#include "Shader.h"

class Model
{
public:
	Model(Model const& model);
	Model(GLuint vaoId = 0, Mesh* mesh = new Mesh(), vec3 position = vec3(0, 0, 0), float size = 1.0, Rotation* rotation = new Rotation(), Texture* texture = new Texture(), Shader* shader = new Shader());
	~Model();
	GLuint& vaoId();
	GLuint getVaoId() const;
	void setVaoId(GLuint vaoId);
	Mesh* getMesh() const;
	void setMesh(Mesh* mesh);
	vec3 getPosition() const;
	void setPosition(vec3 position);
	float getSize() const;
	void setSize(float size);
	Rotation* getRotation() const;
	void setRotation(Rotation* rotation);
	Texture* getTexture() const;
	void setTexture(Texture* texture);
	Shader* getShader() const;
	void setShader(Shader* shader);

private:
	GLuint m_vaoId;
	Mesh* m_mesh;
	vec3 m_position;
	float m_size;
	Rotation* m_rotation;
	Texture* m_texture;
	Shader* m_shader;
};