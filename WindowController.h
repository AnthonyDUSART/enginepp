#pragma once
#include <SDL2/SDL.h>
#include <iostream>
#include "Window.h"

#ifdef _WIN32
#include <GL/glew.h>

#elif __linux__
#define GL3_PROTOTYPES 1
#include <GL3/gl3.h>
#endif // _WIN32

class WindowController
{
public:
	static int createWindow(Window* window);
	static void destroyWindow(Window* window);
	static void updateWindow(Window* window);
};

