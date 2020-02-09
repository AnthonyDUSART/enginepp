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
	~Texture();
	bool load();
	SDL_Surface* reversePixels(SDL_Surface* imgSDL) const;
	Texture& operator=(Texture const& texture);
	GLuint getId() const;
	void setId(GLuint id);
	std::string getFile() const;
	void setFile(std::string file);

private:
	GLuint m_id;
	std::string m_file;
};

