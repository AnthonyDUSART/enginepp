#include "WindowController.h"

int WindowController::createWindow(Window* window) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		std::cout << "Erreur d'initialisation de la SDL : " << SDL_GetError() << std::endl;
		SDL_Quit();

		return -1;
	}

	SDL_Window* context = SDL_CreateWindow(
		window->getTitle().c_str(),
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		window->getWidth(),
		window->getHeight(),
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
	);

	if (context == 0) {
		std::cout << "Erreur de création de la fenetre : " << SDL_GetError() << std::endl;
		SDL_Quit();

		return -1;
	}

	window->setContext(context);

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 1);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);

	SDL_GLContext contextGL = SDL_GL_CreateContext(context);


	if (contextGL == 0) {
		std::cout << "Erreur lors de la création du contexte OpenGL : " << SDL_GetError() << std::endl;
		SDL_DestroyWindow(window->getContext());
		SDL_Quit();
		return -1;
	}

	window->setGlContext(&contextGL);

	GLenum initGlew = glewInit();

	if (initGlew != GLEW_OK) {
		std::cout << "Erreur d'initialisation de GLEW : " << glewGetErrorString(initGlew) << std::endl;
		SDL_GL_DeleteContext(window->getGlContext());
		SDL_DestroyWindow(window->getContext());
		SDL_Quit();
	}

	glEnable(GL_DEPTH_TEST);

	return 0;
}

void WindowController::destroyWindow(Window* window) {
	SDL_GL_DeleteContext(window->getGlContext());
	SDL_DestroyWindow(window->getContext());
	SDL_Quit();
}

void WindowController::updateWindow(Window* window) {
	SDL_GL_SwapWindow(window->getContext());
}