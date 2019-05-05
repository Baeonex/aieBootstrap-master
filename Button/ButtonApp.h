#pragma once

#include "Application.h"
#include "Renderer2D.h"
#include "Button.h"
#include "LinkedListDemo.h"
class ButtonApp : public aie::Application {
public:

	ButtonApp();
	virtual ~ButtonApp();

	virtual bool startup();
	virtual void shutdown();
	void Random();
	virtual void update(float deltaTime);
	virtual void draw();
	void ballDraw();
	bool checkFail(bool &notEnd);
	int CompareLists(LinkedList* list1, LinkedList* list2);
protected:
	bool notEnd;
	int correctCounter;
	bool failInput;
	char* charCorrectCounter;
	LinkedList* answerList;
	LinkedList* list;
	int randomNumber;
	aie::Renderer2D*	m_2dRenderer;
	aie::Font*			m_font;
	Button* m_startButton;
	Button* m_buttonYellow;
	Button* m_buttonBlue;
	Button* m_buttonRed;
	Button* m_buttonGreen;
	aie::Texture* ball;
	aie::Texture* yellow;
	aie::Texture* blue;
	aie::Texture* red;
	aie::Texture* green;
};