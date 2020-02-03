#include "Texture.h"

Texture::Texture(Texture const& texture) {
	m_file = texture.getFile();
	load();
}

Texture::Texture(std::string file) {
	m_id = 0;
	m_file = file;
;}

Texture::~Texture() {
	glDeleteTextures(0, &m_id);
}

bool Texture::load() {
	SDL_Surface* imgSource = IMG_Load(m_file.c_str());

	if (imgSource == 0) {
		std::cout << "Le chargement de l'image: \"" << m_file << "\" a échoué. Erreur: " << SDL_GetError() << std::endl;
		return false;
	}

	SDL_Surface* img = reversePixels(imgSource);
	SDL_FreeSurface(imgSource);

	if (glIsTexture(m_id) == GL_TRUE)
		glDeleteTextures(1, &m_id);

	glGenTextures(1, &m_id);

	// verrouillage
	glBindTexture(GL_TEXTURE_2D, m_id);
	
	GLenum internalFormat = 0;
	GLenum format = 0;
	if (img->format->BytesPerPixel == 3) {
		internalFormat = GL_RGB;

		if (img->format->Rmask == 0xFF)
			format = GL_RGB;
		else
			format = GL_BGR;
	}
	else if (img->format->BytesPerPixel == 4) {
		internalFormat = GL_RGBA;
		if (img->format->Rmask == 0xFF)
			format = GL_RGBA;
		else
			format = GL_BGRA;
	}
	else {
		std::cout << "Erreur, format d'image non reconnu" << std::endl;
		SDL_FreeSurface(img);
		return false;
	}

	glTexImage2D(GL_TEXTURE_2D, 0, internalFormat, img->w, img->h, 0, format, GL_UNSIGNED_BYTE, img->pixels);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

	// deverrouillage
	glBindTexture(GL_TEXTURE_2D, 0);
	SDL_FreeSurface(img);
	return true;
}

SDL_Surface* Texture::reversePixels(SDL_Surface* imgSDL) const {


	SDL_Surface* imgCopy = SDL_CreateRGBSurface(
		0, 
		imgSDL->w, 
		imgSDL->h,
		imgSDL->format->BitsPerPixel,
		imgSDL->format->Rmask,
		imgSDL->format->Gmask,
		imgSDL->format->Bmask,
		imgSDL->format->Amask
	);

	unsigned char* imgPixels = (unsigned char*)imgSDL->pixels;
	unsigned char* imgCopyPixels = (unsigned char*)imgCopy->pixels;

	for (int i = 0; i < imgSDL->h; i++)
	{
		for (int j = 0; j < imgSDL->w * imgSDL->format->BytesPerPixel; j++)
			imgCopyPixels[(imgSDL->w * imgSDL->format->BytesPerPixel * (imgSDL->h - 1 - i)) + j] = imgPixels[(imgSDL->w * imgSDL->format->BytesPerPixel * i) + j];
	}

	return imgCopy;
}

Texture& Texture::operator=(Texture const& texture) {
	m_file = texture.getFile();
	load();
	return *this;
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