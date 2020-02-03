#include "Rotation.h"

Rotation::Rotation(float angle, vec3 axis) {
	m_angle = angle;
	m_axis = axis;
}

float Rotation::getAngle() const {
	return m_angle;
}

void Rotation::setAngle(float angle) {
	m_angle = angle;
}

vec3 Rotation::getAxis() const {
	return m_axis;
}

void Rotation::setAxis(vec3 axis) {
	m_axis = axis;
}