#include "ColorShader.h"

ColorShader::ColorShader() : Shader("Shader/couleur3D.vert", "Shader/couleur3D.frag") {
    addAttribute(0, "in_Vertex");
    addAttribute(1, "in_Color");
}