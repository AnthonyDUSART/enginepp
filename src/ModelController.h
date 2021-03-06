#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <regex>
#include <iostream>
#include <sstream>
#include <fstream>
#include "Model.h"
#include "MeshController.h"
#include "ShaderController.h"
#include "TextureController.h"
#include "FrameBufferController.h"

#define BUFFER_OFFSET(offset) ((char*)NULL + (offset))

using namespace std;

class ModelController
{
public:
	static void load(Model* model);
	static void render(Model* model, mat4 &projection, mat4 &modelview);
	static void render(Model* model, GLuint textureId, mat4 &projection, mat4 &modelview);
};

