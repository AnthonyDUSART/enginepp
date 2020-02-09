#include "TextureShader.h"

TextureShader::TextureShader() : Shader("Shader/texture.vert", "Shader/texture.frag") {
    addAttribute(0, "in_Vertex");
    addAttribute(1, "in_Color");
    addAttribute(2, "in_TexCoord0");
}
