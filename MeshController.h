#pragma once

#include <SDL2/SDL.h>
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include "Mesh.h"
#define BUFFER_OFFSET(offset) ((char*)NULL + (offset))

class MeshController
{
public:
	static void loadObj(Mesh* mesh, std::string file);
	static void load(Mesh* mesh);
};

