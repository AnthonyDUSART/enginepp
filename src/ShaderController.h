#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include <GL/glew.h>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>

#include "Shader.h"

class ShaderController
{
public:
    static bool compile(GLuint &id, GLenum type, std::string const &file);
    static bool load(Shader* shader);
    static void loadMatrix4f(Shader* shader, std::string name, glm::mat4 matrix);
};