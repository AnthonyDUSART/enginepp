#pragma once

#include "Window.h"
#include "Shader.h"
#include "Input.h"

class Scene
{
public:
	Scene(Window* window = nullptr, Shader* shader = nullptr, Input* input = new Input());
	~Scene();
	Window* getWindow() const;
	void setWindow(Window* window);
	Shader* getShader() const;
	void setShader(Shader* shader);
	Input* getInput() const;
	void setInput(Input* input);

private:
	Window* m_window;
	Shader* m_shader;
	Input* m_input;

};

