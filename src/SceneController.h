#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "WindowController.h"
#include "Scene.h"
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

