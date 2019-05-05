#pragma once
#include "Renderer2D.h"
#include "Font.h"
#include "Application.h"
#include "Renderer2D.h"
#include "Input.h"
#include "Texture.h"

class Button
{
public:
	Button(const char* buttonText, float x, float y, float width, float height, aie::Texture* img);
	~Button();
	void Draw(aie::Renderer2D* renderer);
	bool Update();
private:
	//Font and text for the button.
	aie::Font* m_font;
	char m_buttonText[64];
	//Button's position, width, and height.
	float m_posX;
	float m_posY;
	float m_width;
	float m_height;
	aie::Texture* colourImg;
};

