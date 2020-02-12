#include "FrameBuffer.h"

FrameBuffer::FrameBuffer(float height, float width, GLuint id, GLuint depthBufferId, std::vector<Texture> colorBuffers) {
    m_height = height;
    m_width = width;
    m_id = id;
    m_depthBufferId = depthBufferId;
    m_colorBuffers = colorBuffers;
}

FrameBuffer::~FrameBuffer() {
    glDeleteFramebuffers(1, &m_id);
    glDeleteRenderbuffers(1, &m_depthBufferId);
    m_colorBuffers.clear();
}

GLuint& FrameBuffer::id() {
    return m_id;
}

GLuint FrameBuffer::getId() const {
    return m_id;
}

void FrameBuffer::setId(GLuint id) {
    m_id = id;
}

float FrameBuffer::getHeight() const {
    return m_height;
}

void FrameBuffer::setHeight(float height) {
    m_height = height;
}

float FrameBuffer::getWidth() const {
    return m_width;
}

void FrameBuffer::setWidth(float width) {
    m_width = width;
}

std::vector<Texture> FrameBuffer::getColorBuffers() const {
    return m_colorBuffers;
}

void FrameBuffer::setColorBuffers(std::vector<Texture> colorBuffers) {
    m_colorBuffers = colorBuffers;
}

void FrameBuffer::addColorBuffer(Texture colorBuffer) {
    m_colorBuffers.push_back(colorBuffer);
}

GLuint& FrameBuffer::depthBufferId() {
    return m_depthBufferId;
}

GLuint FrameBuffer::getDepthBufferId() const {
    return m_depthBufferId;
}

void FrameBuffer::setDepthBufferId(GLuint depthBufferId) {
    m_depthBufferId = depthBufferId;
}