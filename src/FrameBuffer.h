#pragma once

#include <GL/glew.h>
#include <vector>
#include "Texture.h"

class FrameBuffer
{
private:
    GLuint m_id;
    float m_height;
    float m_width;
    std::vector<Texture> m_colorBuffers;
    GLuint m_depthBufferId;

public:
    FrameBuffer(float height = 0.0f, float width = 0.0f, GLuint id = 0, GLuint depthBufferId = 0, std::vector<Texture> colorBuffers = std::vector<Texture>());
    ~FrameBuffer();
    GLuint& id();
    GLuint getId() const;
    void setId(GLuint id);
    float getHeight() const;
    void setHeight(float height);
    float getWidth() const;
    void setWidth(float width);
    std::vector<Texture> getColorBuffers() const;
    void setColorBuffers(std::vector<Texture> colorBuffers);
    void addColorBuffer(Texture colorBuffer);
    GLuint& depthBufferId();
    GLuint getDepthBufferId() const;
    void setDepthBufferId(GLuint depthBufferId);
};
