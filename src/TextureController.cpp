#include "TextureController.h"

void TextureController::loadEmpty(Texture* texture) {

    if(glIsTexture(texture->getId()))
        glDeleteTextures(1, &texture->id());
    
    glGenTextures(1, &texture->id());

    glBindTexture(GL_TEXTURE_2D, texture->getId());
    {
        // generate empty texture
        glTexImage2D(
            GL_TEXTURE_2D, 
            0, 
            texture->getInternalFormat(),
            texture->getWidth(),
            texture->getHeight(),
            0,
            texture->getFormat(),
            GL_UNSIGNED_BYTE,
            0
        );

        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
        glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

    }
    glBindTexture(GL_TEXTURE_2D, 0);

}

bool TextureController::load(Texture* texture) {
    SDL_Surface* imgSource = IMG_Load(texture->getFile().c_str());

	if (imgSource == 0) {
		std::cout << "Le chargement de l'image: \"" << texture->getFile() << "\" a �chou�. Erreur: " << SDL_GetError() << std::endl;
		return false;
	}

	SDL_Surface* img = reversePixels(imgSource);
    
	SDL_FreeSurface(imgSource);

	if (glIsTexture(texture->getId()) == GL_TRUE)
		glDeleteTextures(1, &texture->id());

	glGenTextures(1, &texture->id());

	// verrouillage
	glBindTexture(GL_TEXTURE_2D, texture->getId());
	
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

Texture* TextureController::check(Texture* texture) {

    if(glIsTexture(texture->getId() == GL_TRUE)) {
        if(texture->isEmpty())
            TextureController::loadEmpty(texture);
        else
            TextureController::load(texture);
    }
    
    return texture;
}

Texture* TextureController::copy(Texture const &source) {
    return TextureController::check(
        new Texture(source)
    );
}

void TextureController::copy(Texture const &source, Texture* destination) {
    *destination = source;
    TextureController::check(destination);
}

SDL_Surface* TextureController::reversePixels(SDL_Surface* img) {
    SDL_Surface* imgCopy = SDL_CreateRGBSurface(
		0, 
		img->w, 
		img->h,
		img->format->BitsPerPixel,
		img->format->Rmask,
		img->format->Gmask,
		img->format->Bmask,
		img->format->Amask
	);

	unsigned char* imgPixels = (unsigned char*)img->pixels;
	unsigned char* imgCopyPixels = (unsigned char*)imgCopy->pixels;

	for (int i = 0; i < img->h; i++)
	{
		for (int j = 0; j < img->w * img->format->BytesPerPixel; j++)
			imgCopyPixels[(img->w * img->format->BytesPerPixel * (img->h - 1 - i)) + j] = imgPixels[(img->w * img->format->BytesPerPixel * i) + j];
	}

	return imgCopy;
}