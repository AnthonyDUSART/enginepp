#pragma once

#define GLM_ENABLE_EXPERIMENTAL

#include <glm/glm.hpp>
#include <glm/gtx/transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <GL/glew.h>
#include "FrameBuffer.h"
#include "Texture.h"
#include "TextureController.h"
#include "Model.h"
#include "ShaderController.h"

class FrameBufferController
{
public:
    static bool load(FrameBuffer* frameBuffer);
    static GLuint createBufferRender(GLuint &id, float width, float height, GLenum internalFormat);
    static void render(FrameBuffer* frameBuffer, Model* model, glm::mat4 &projection, glm::mat4 &modelview);
};
