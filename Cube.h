#pragma once
#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"
#include "ColorShader.h"
#include "Rotation.h"

using namespace glm;

class Cube
{

public:
	Cube(float size, vec3 coords = vec3(0.0), Rotation* rotation = new Rotation(), Shader* shader = new ColorShader());
	~Cube();
	Shader* getShader() const;
	void setShader(Shader* shader);
	float getSize() const;
	void setSize(float size);
	vec3 getCoords() const;
	void setCoords(vec3 coords);
	Rotation* getRotation() const;
	void setRotation(Rotation* rotation);
	virtual void show(glm::mat4 &projection, glm::mat4 &modelview) = 0;

protected:
	Shader* m_shader;
	float m_size;
	vec3 m_coords;
	Rotation* m_rotation;
	float m_vertices[108];
	float m_colors[108];
};

