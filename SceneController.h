#pragma once

#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Scene.h"
#include "WindowController.h"
#include "Cube.h"
#include "TexturedCube.h"
#include "Input.h"
#include "Texture.h"
#include "TextureShader.h"
#include "Camera.h"
#include "MeshController.h"
#include "ModelController.h"

using namespace glm;

class SceneController
{
public:
	static void createScene(Scene* scene);
	static void destroyScene(Scene* scene);
	static void loopScene(Scene* scene);
};

