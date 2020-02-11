#include "SceneController.h"

void SceneController::createScene(Scene* scene) {
	Window* window = new Window("Learning OpenGL", 800, 600);
	WindowController::createWindow(window);

	scene->setWindow(window);
}

void SceneController::destroyScene(Scene* scene) {
	WindowController::destroyWindow(scene->getWindow());
}

void SceneController::loopScene(Scene* scene) {
	bool run = true;

	// matrice de projection
	mat4 projection;
	mat4 modelview;
	projection = perspective(
		70.0,
		(double)scene->getWindow()->getWidth() / scene->getWindow()->getHeight(),
		1.0,
		1000.0
	);
	modelview = mat4(1.0);


	unsigned int framerate = 1000 / 60;
	Uint32 beginTime(0), endTime(0), countTime(0);

	scene->getInput()->lockCursor(true);
	scene->getInput()->showCursor(false);
	float angle(0.0);

	Camera camera = Camera(glm::vec3(0, -40, 0));
	
	Model model = Model();

	Texture* texture = new Texture("Texture/photorealistic/photorealistic_bricks/brick004.jpg");
	//TextureController::load(texture);

	TextureShader* shader = new TextureShader();

	model.setTexture(texture);
	model.setShader(shader);

	MeshController::loadObj(model.getMesh(), "Model/teapot.obj");
	ModelController::load(&model);
	
	//model.setMesh(mesh);
	

	//TexturedCube cube = TexturedCube(10, vec3(0, 0, 0), new Rotation(0.0f), &texture, &shader);
	

	while (run) {
		beginTime = SDL_GetTicks();
		scene->getInput()->listen();
		if (scene->getInput()->getClose())
			run = false;

		if (!scene->getInput()->cursorIsShowed()) {
			camera.move(*scene->getInput());
			if (scene->getInput()->getKeyboardKey(SDL_SCANCODE_ESCAPE)) {
				scene->getInput()->showCursor(true);
				scene->getInput()->lockCursor(false);
			}
		}
		else {
			if (scene->getInput()->getKeyboardKey(SDL_SCANCODE_ESCAPE)) {
				scene->getInput()->showCursor(false);
				scene->getInput()->lockCursor(true);
			}
		}


		// nettoyage de l'ecran
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		// Camera
		//modelview = lookAt(vec3(2, 2, 8), vec3(0, 0, 0), vec3(0, 1, 0));
		camera.lookAt(modelview);

		angle += 0.01;
		if (angle >= 360)
			angle = 0.0;

		model.getRotation()->setAxis(glm::vec3(0.0, 1.0, 0.0));
		model.getRotation()->setAngle(angle);

		//cube.getRotation()->setAngle(angle);
		//cube.show(projection, modelview);
		ModelController::render(&model, projection, modelview);
		

		WindowController::updateWindow(scene->getWindow());

		endTime = SDL_GetTicks();
		countTime = endTime - beginTime;
		if (countTime < framerate)
			SDL_Delay(framerate - countTime);
	}
}