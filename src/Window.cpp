#include "Window.h"

Window::Window(std::string title, int width, int height, SDL_Window* context, SDL_GLContext* glContext) {
	m_title = title;
	m_width = width;
	m_height = height;
	m_context = context;
	m_glContext = glContext;
	m_events = new SDL_Event();
}

Window::~Window() {
	delete m_events;
	SDL_GL_DeleteContext(m_context);
	SDL_DestroyWindow(m_context);
}

std::string Window::getTitle() const
{
	return m_title;
}

void Window::setTitle(std::string title) {
	m_title = title;
}

int Window::getWidth() const {
	return m_width;
}

void Window::setWidth(int width) {
	m_width = width;
}

int Window::getHeight() const {
	return m_height;
}

void Window::setHeight(int height) {
	m_height = height;
}

SDL_Window* Window::getContext() const {
	return m_context;
}

void Window::setContext(SDL_Window* context) {
	m_context = context;
}

SDL_GLContext* Window::getGlContext() const {
	return m_glContext;
}

void Window::setGlContext(SDL_GLContext* glContext) {
	m_glContext = glContext;
}

SDL_Event* Window::getEvents() const {
	return m_events;
}
