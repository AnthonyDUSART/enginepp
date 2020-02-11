#pragma once

#include <GL/glew.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include "Texture.h"

class TextureController
{
public:
    static void loadEmpty(Texture* texture);
    static bool load(Texture* texture);
    static Texture* copy(Texture const &source);
    static void copy(Texture const &source, Texture* destination);
    static Texture* check(Texture* texture);
    static SDL_Surface* reversePixels(SDL_Surface* img);
};