#pragma once


// Include Windows

#ifdef _WIN32
#include <GL/glew.h>


// Include Mac

#elif __APPLE__
#define GL3_PROTOTYPES 1
#include <OpenGL/gl3.h>


// Include UNIX/Linux

#elif __linux__
#define GL3_PROTOTYPES 1
#include <GL3/gl3.h>
#endif // _WIN32


// Includes communs

#include <iostream>
#include <string>
#include <fstream>


// Classe Shader

class Shader
{
public:

	Shader();
	Shader(Shader const& shaderACopier);
	Shader(std::string vertexSource, std::string fragmentSource);
	~Shader();

	Shader& operator=(Shader const& shaderACopier);

	virtual bool charger();
	bool compilerShader(GLuint& shader, GLenum type, std::string const& fichierSource);
	GLuint getProgramID() const;


private:

	GLuint m_vertexID;
	GLuint m_fragmentID;
	GLuint m_programID;

	std::string m_vertexSource;
	std::string m_fragmentSource;
};
