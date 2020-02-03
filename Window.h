#pragma once
#include <string>
#include <SDL2/SDL.h>

class Window
{
public:
	Window(std::string title, int width, int height, SDL_Window* context = nullptr, SDL_GLContext* glContext = nullptr);
	~Window();
	std::string getTitle() const;
	void setTitle(std::string title);
	int getWidth() const;
	void setWidth(int width);
	int getHeight() const;
	void setHeight(int height);
	SDL_Window* getContext() const;
	void setContext(SDL_Window* context);
	SDL_GLContext* getGlContext() const;
	void setGlContext(SDL_GLContext* glContext);
	SDL_Event* getEvents() const;

private:
	std::string m_title;
	int m_width;
	int m_height;
	SDL_Window* m_context;
	SDL_GLContext* m_glContext;
	SDL_Event* m_events;
};

