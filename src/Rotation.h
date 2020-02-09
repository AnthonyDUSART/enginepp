#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;
class Rotation
{
public:
	Rotation(float angle = 0.0, vec3 axis = vec3(1.0, 0.0, 0.0));
	float getAngle() const;
	void setAngle(float angle);
	vec3 getAxis() const;
	void setAxis(vec3 axis);

private:
	float m_angle;
	vec3 m_axis;
};

