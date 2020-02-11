#pragma once

#ifdef _WIN32
#include <GL/glew.h>

#elif __linux__
#define GL3_PROTOTYPES 1
#define GL_GLEXT_PROTOTYPES
#include <GL/gl.h>
#endif // _WIN32

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <iostream>
#include <string>

class Texture
{
public:
	Texture(Texture const& texture);
	Texture(std::string file = "");
	Texture(int height, int width, GLenum format, GLenum internalFormat, bool isEmpty, std::string file = "", GLuint id = 0);
	~Texture();
	Texture& operator=(Texture const& texture);
	GLuint& id();
	GLuint getId() const;
	void setId(GLuint id);
	std::string getFile() const;
	void setFile(std::string file);
	int getHeight() const;
	void setHeight(int height);
	int getWidth() const;
	void setWidth(int width);
	GLenum getFormat() const;
	void setFormat(GLenum format);
	GLenum getInternalFormat() const;
	void setInternalFormat(GLenum internalFormat);
	bool isEmpty() const;

private:
	GLuint m_id;
	std::string m_file;
	int m_height;
	int m_width;
	GLenum m_format;
	GLenum m_internalFormat;
	bool m_isEmpty;
};

