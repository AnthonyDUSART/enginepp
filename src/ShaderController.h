#pragma once

#include <iostream>
#include <string>
#include <fstream>

#include <GL/glew.h>

#include "Shader.h"

class ShaderController
{
public:
    static bool compile(GLuint &id, GLenum type, std::string const &file);
    static bool load(Shader* shader);
};