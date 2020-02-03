#pragma once
#define _USE_MATH_DEFINES
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include "Input.h"

class Camera
{
public:
	Camera(glm::vec3 position = glm::vec3(), glm::vec3 verticalAxis = glm::vec3(0, 0, 1), glm::vec3 center = glm::vec3(), glm::vec3 orientation = glm::vec3(), glm::vec3 lateralDisplacement = glm::vec3(), float theta = 0.0, float phi = 0.0, float speed = 0.5, float sensibility = 0.5);
	~Camera();
	void orientate(int xReal, int yReal);
	void move(Input const& input);
	void lookAt(glm::mat4 &modelview);
	float getPhi() const;
	void setPhi(float phi);
	float getTheta() const;
	void setTheta(float theta);
	glm::vec3 getOrientation() const;
	void setOrientation(glm::vec3 orientation);
	glm::vec3 getVerticalAxis() const;
	void setVerticalAxis(glm::vec3 verticalAxis);
	glm::vec3 getLateralDisplacement() const;
	void setLateralDisplacement(glm::vec3 lateralDisplacement);
	glm::vec3 getPosition() const;
	void setPosition(glm::vec3 position);
	glm::vec3 getCenter() const;
	void setCenter(glm::vec3 center);
	float getSpeed() const;
	void setSpeed(float speed);
	float getSensibility() const;
	void setSensibility(float sensibility);


private:
	float m_phi;
	float m_theta;
	glm::vec3 m_orientation;
	glm::vec3 m_verticalAxis;
	glm::vec3 m_lateralDisplacement;
	glm::vec3 m_position;
	glm::vec3 m_center;
	float m_speed;
	float m_sensibility;
};

