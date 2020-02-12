#pragma once

#include <GL/glew.h>
#include "FrameBuffer.h"
#include "Texture.h"
#include "TextureController.h"

class FrameBufferController
{
public:
    static bool load(FrameBuffer* frameBuffer);
    static GLuint createBufferRender(GLuint &id, float width, float height, GLenum internalFormat);
};
