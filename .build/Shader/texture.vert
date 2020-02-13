// Version du GLSL

#version 150 core


// Entrees

in vec3 in_Vertex;
in vec2 in_TexCoord0;
//in float in_Size;

// Uniform

uniform mat4 modelviewProjection;


// Sortie

out vec2 coordTexture;


// Fonction main

void main()
{
    // Position finale du vertex en 3D

    gl_Position = modelviewProjection * vec4(in_Vertex, 1.0);


    // Envoi des coordonnées de texture au Fragment Shader

    coordTexture = in_TexCoord0;
}
