#define SDL_MAIN_HANDLED
#include "SceneController.h"
#include <iostream>

int main(int argc, char **argv) {
	Scene scene = Scene();
	SceneController::createScene(&scene);
	SceneController::loopScene(&scene);
	SceneController::destroyScene(&scene);
	return 0;
}