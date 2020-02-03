#pragma once

#include "Cube.h"
#include "Texture.h"
#include "TextureShader.h"

class TexturedCube : public Cube
{
public:
	TexturedCube(float size, vec3 coords = vec3(0.0), Rotation* rotation = new Rotation(), Texture* texture = new Texture(), TextureShader* shader = new TextureShader());
	~TexturedCube();
	void show(glm::mat4& projection, glm::mat4& modelview);
	Texture* getTexture() const;
	void setTexture(Texture* texture);
private:
	Texture* m_texture;
	float m_textureCoords[72];
	
};

