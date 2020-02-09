#include "Scene.h"

Scene::Scene(Window* window, Shader* shader, Input* input) {
	m_window = window;
	m_shader = shader;
	m_input = input;
}

Scene::~Scene() {
	delete m_window;
	delete m_shader;
	delete m_input;
}

Window* Scene::getWindow() const {
	return m_window;
}

void Scene::setWindow(Window* window) {
	m_window = window;
}

Shader* Scene::getShader() const {
	return m_shader;
}

void Scene::setShader(Shader* shader) {
	m_shader = shader;
}

Input* Scene::getInput() const {
	return m_input;
}

void Scene::setInput(Input* input) {
	m_input = input;
}