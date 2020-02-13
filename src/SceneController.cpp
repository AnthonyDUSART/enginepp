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

	FrameBuffer frameBuffer = FrameBuffer(512.0, 512.0);
	FrameBufferController::load(&frameBuffer);



	// matrice de projection
	mat4 projection, projectionFBO;
	mat4 modelview, modelviewFBO;

	projection = perspective(
		70.0,
		(double)scene->getWindow()->getWidth() / scene->getWindow()->getHeight(),
		1.0,
		1000.0
	);

	projectionFBO = perspective(
		70.0,
		(double)frameBuffer.getWidth() / frameBuffer.getHeight(),
		1.0,
		1000.0
	);
	modelview = mat4(1.0);
	modelviewFBO = mat4(1.0);


	unsigned int framerate = 1000 / 60;
	Uint32 beginTime(0), endTime(0), countTime(0);

	scene->getInput()->lockCursor(true);
	scene->getInput()->showCursor(false);
	float angle(0.0);

	Camera camera = Camera(glm::vec3(0, -40, 0));

	Model brickCube = Model();
	Texture* brickTexture = new Texture("Texture/photorealistic/photorealistic_bricks/brick002.jpg");
	TextureShader* shaderBrick = new TextureShader();

	brickCube.setTexture(brickTexture);
	brickCube.setShader(shaderBrick);

	MeshController::loadObj(brickCube.getMesh(), "Model/teapot.obj");
	ModelController::load(&brickCube);

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
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		camera.lookAt(modelview);

		modelviewFBO = lookAt(vec3(3, 0, 3), vec3(0, 0, 0), vec3(0, 1, 0));

		brickCube.getRotation()->setAxis(glm::vec3(1.0, 0.0, 0.0));
		brickCube.getRotation()->setAngle(angle);

		ModelController::render(&brickCube, projection, modelview);

		WindowController::updateWindow(scene->getWindow());

		endTime = SDL_GetTicks();
		countTime = endTime - beginTime;
		if (countTime < framerate)
			SDL_Delay(framerate - countTime);
	}
}