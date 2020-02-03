#include "Camera.h"

Camera::Camera(glm::vec3 position, glm::vec3 verticalAxis, glm::vec3 center, glm::vec3 orientation, glm::vec3 lateralDisplacement, float theta, float phi, float speed, float sensibility) {
	m_position = position;
	m_verticalAxis = verticalAxis;
	m_orientation = orientation;
	m_lateralDisplacement = lateralDisplacement;
	m_theta = theta;
	m_phi = phi;
	m_center = center;
	m_speed = speed;
	m_sensibility = sensibility;
	setCenter(center);
	orientate(0, 0);
}

Camera::~Camera() {

}

void Camera::orientate(int xReal, int yReal) {
	m_phi += -yReal * m_sensibility;
	m_theta += -xReal * m_sensibility;
	if (m_phi > 89.0)
		m_phi = 89.0;
	else if (m_phi < -89.0)
		m_phi = -89.0;

	float phiRadian = m_phi * M_PI / 180;
	float thetaRadian = m_theta * M_PI / 180;

	if (m_verticalAxis.x == 1.0) {
		m_orientation.x = sin(phiRadian);
		m_orientation.y = cos(phiRadian) * cos(thetaRadian);
		m_orientation.z = cos(phiRadian) * sin(thetaRadian);
	}
	else if (m_verticalAxis.y == 1.0) {
		m_orientation.x = cos(phiRadian) * sin(thetaRadian);
		m_orientation.y = sin(phiRadian);
		m_orientation.z = cos(phiRadian) * cos(thetaRadian);
	}
	else {
		m_orientation.x = cos(phiRadian) * cos(thetaRadian);
		m_orientation.y = cos(phiRadian) * sin(thetaRadian);
		m_orientation.z = sin(phiRadian);
	}

	m_lateralDisplacement = glm::cross(m_verticalAxis, m_orientation);
	m_lateralDisplacement = glm::normalize(m_lateralDisplacement);

	m_center = m_position + m_orientation;
}

void Camera::move(Input const& input) {

	if (input.mouseIsMoved()) {
		orientate(input.getXReal(), input.getYReal());
	}

	if (input.getKeyboardKey(SDL_SCANCODE_UP)) {
		m_position += m_orientation * m_speed;
		m_center = m_position + m_orientation;
	}
	if (input.getKeyboardKey(SDL_SCANCODE_DOWN)) {
		m_position -= m_orientation * m_speed;
		m_center = m_position + m_orientation;
	}
	if (input.getKeyboardKey(SDL_SCANCODE_LEFT)) {
		m_position += m_lateralDisplacement * m_speed;
		m_center = m_position + m_orientation;
	}
	if (input.getKeyboardKey(SDL_SCANCODE_RIGHT)) {
		m_position -= m_lateralDisplacement * m_speed;
		m_center = m_position + m_orientation;
	}
}

void Camera::lookAt(glm::mat4& modelview) {
	modelview = glm::lookAt(m_position, m_center, m_verticalAxis);
}

float Camera::getPhi() const {
	return m_phi;
}

void Camera::setPhi(float phi) {
	m_phi = phi;
}

float Camera::getTheta() const {
	return m_theta;
}

void Camera::setTheta(float theta) {
	m_theta = theta;
}

glm::vec3 Camera::getOrientation() const {
	return m_orientation;
}

void Camera::setOrientation(glm::vec3 orientation) {
	m_orientation = orientation;
}

glm::vec3 Camera::getVerticalAxis() const {
	return m_verticalAxis;
}

void Camera::setVerticalAxis(glm::vec3 verticalAxis) {
	m_verticalAxis = verticalAxis;
}

glm::vec3 Camera::getLateralDisplacement() const {
	return m_lateralDisplacement;
}

void Camera::setLateralDisplacement(glm::vec3 lateralDisplacement) {
	m_lateralDisplacement = lateralDisplacement;
}

glm::vec3 Camera::getPosition() const {
	return m_position;
}

void Camera::setPosition(glm::vec3 position) {
	m_position = position;

	m_center = m_position + m_orientation;
}

glm::vec3 Camera::getCenter() const {
	return m_center;
}

void Camera::setCenter(glm::vec3 center) {
	//m_center = center;

	m_orientation = m_center - m_position;
	m_orientation = glm::normalize(m_orientation);

	if (m_verticalAxis.x == 1.0) {
		m_phi = asin(m_orientation.x);
		m_theta = acos(m_orientation.y / cos(m_phi));
		if (m_orientation.y < 0)
			m_theta *= -1;
	}
	else if (m_verticalAxis.y == 1.0) {
		m_phi = asin(m_orientation.y);
		m_theta = acos(m_orientation.z / cos(m_phi));
		if (m_orientation.z < 0)
			m_theta *= -1;
	}
	else {
		m_phi = asin(m_orientation.x);
		m_theta = acos(m_orientation.z / cos(m_phi));
		if (m_orientation.z < 0)
			m_theta *= -1;
	}

	m_phi *= 180 / M_PI;
	m_theta *= 180 / M_PI;
}

float Camera::getSpeed() const {
	return m_speed;
}

void Camera::setSpeed(float speed) {
	m_speed = speed;
}

float Camera::getSensibility() const {
	return m_sensibility;
}

void Camera::setSensibility(float sensibility) {
	m_sensibility = sensibility;
}