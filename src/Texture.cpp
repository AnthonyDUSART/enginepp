#include "Texture.h"

Texture::Texture(Texture const& texture) {
	*this = texture;
}

Texture::Texture(std::string file) {
	m_id = 0;
	m_file = file;
}

Texture::Texture(int height, int width, GLenum format, GLenum internalFormat, bool isEmpty, std::string file, GLuint id) {
	m_height = height;
	m_width = width;
	m_format = format;
	m_internalFormat = internalFormat;
	m_isEmpty = isEmpty;
	m_id = id;
	m_file = file;
}

Texture::~Texture() {
	glDeleteTextures(0, &m_id);
}

Texture& Texture::operator=(Texture const& texture) {
	m_file = texture.getFile();
	m_height = texture.getHeight();
	m_width = texture.getWidth();
	m_format = texture.getFormat();
	m_internalFormat = texture.getInternalFormat();
	m_isEmpty = texture.isEmpty();

	return *this;
}

GLuint& Texture::id() {
	return m_id;
}

GLuint Texture::getId() const {
	return m_id;
}

void Texture::setId(GLuint id) {
	m_id = id;
}

std::string Texture::getFile() const {
	return m_file;
}

void Texture::setFile(std::string file) {
	m_file = file;
}

int Texture::getHeight() const {
	return m_height;
}

void Texture::setHeight(int height) {
	m_height = height;
}

int Texture::getWidth() const {
	return m_width;
}

void Texture::setWidth(int width) {
	m_width = width;
}

GLenum Texture::getFormat() const {
	return m_format;
}

void Texture::setFormat(GLenum format) {
	m_format = format;
}

GLenum Texture::getInternalFormat() const {
	return m_internalFormat;
}

void Texture::setInternalFormat(GLenum internalFormat) {
	m_internalFormat = internalFormat;
}

bool Texture::isEmpty() const {
	return m_isEmpty;
}