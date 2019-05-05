#include "ButtonApp.h"
#include "Texture.h"
#include "Font.h"
#include "Input.h"
#include <iostream>
ButtonApp::ButtonApp() {

}

ButtonApp::~ButtonApp() {

}

bool ButtonApp::startup() {
	
	m_2dRenderer = new aie::Renderer2D();
	list = new LinkedList;
	answerList = new LinkedList;
	ball = new aie::Texture("../bin/textures/ball.png");
	yellow = new aie::Texture("../bin/textures/yellow.jpg");
	red = new aie::Texture("../bin/textures/Red.jpg");
	blue = new aie::Texture("../bin/textures/Blue.png");
	green = new aie::Texture("../bin/textures/Green.jpg");
	m_startButton = new Button("Play", 900, 100, 120, 50, blue);
	m_buttonYellow = new Button("", 150, 400, 120, 50, yellow);
	m_buttonBlue = new Button("", 300, 400, 120, 50, blue);
	m_buttonGreen = new Button("", 450, 400, 120, 50, green);
	m_buttonRed = new Button("", 600, 400, 120, 50, red);
	// TODO: remember to change this when redistributing a build!
	// the following path would be used instead: "./font/consolas.ttf"
	m_font = new aie::Font("../bin/font/consolas.ttf", 32);

	return true;
}

void ButtonApp::shutdown() {
	delete list;
	delete m_font;
	delete m_2dRenderer;
	delete m_buttonYellow;
	delete m_buttonBlue;
	delete m_buttonGreen;
	delete m_buttonRed;
	delete m_startButton;
	delete yellow;
	delete red;
	delete blue;
	delete green;
	delete answerList;
}

void ButtonApp::update(float deltaTime) {

	// input example

	aie::Input* input = aie::Input::getInstance();

	if (m_startButton->Update())
	{
		notEnd = true;
		Random();
		ballDraw();
		
	}
	if (m_buttonYellow->Update())
	{
		answerList->add(0);
		cout << "answer" << endl;
		answerList->print();
		if (checkFail(notEnd))
			draw();

	}
	if (m_buttonBlue->Update())
	{
		answerList->add(1);
		cout << "answer" << endl;
		answerList->print();
		if (checkFail(notEnd))
			draw();
	}
	if (m_buttonGreen->Update())
	{
		answerList->add(2);
		cout << "answer" << endl;
		answerList->print();
		if (checkFail(notEnd))
			draw();
	}
	if (m_buttonRed->Update())
	{
		answerList->add(3);
		cout << "answer" << endl;
		answerList->print();
		if (checkFail(notEnd))
			draw();
	}
	// exit the application
	if (input->isKeyDown(aie::INPUT_KEY_ESCAPE))
		quit();

}

void ButtonApp::Random()
{
	list->add(rand() % 4);
	cout << "List" << endl;
	list->print();
}
void ButtonApp::ballDraw()
{
	int i = 0;
	while (i < list->size())
	{
		if (list->search(list->size() - i) == 0)
		{
			m_2dRenderer->drawSprite(ball, 150, 400);
		}
		else if (list->search(list->size() - i) == 1)
		{
			m_2dRenderer->drawSprite(ball, 300, 400);
		}
		else if (list->search(list->size() - i) == 2)
		{
			m_2dRenderer->drawSprite(ball, 450, 400);
		}
		else if (list->search(list->size() - i) == 3)
		{
			m_2dRenderer->drawSprite(ball, 600, 400);
		}
		++i;
	}
}

bool ButtonApp::checkFail(bool &notEnd)
{
	//notEnd = answerList->areIdentical(answerList->head, list->head);

	cout << "answerLength: " << answerList->length << endl;
	cout << "ListLength: " << list->length << endl;
	if (answerList->length == list->length)
	{
		notEnd = answerList->areIdentical(answerList->head, list->head);
		answerList->clearList();
		answerList->length = 0;
	}
	return notEnd;
	
}

int ButtonApp::CompareLists(LinkedList* list1, LinkedList* list2)
{
	return 0;
}

void ButtonApp::draw() {

	// wipe the screen to the background colour
	clearScreen();

	// begin drawing sprites
	m_2dRenderer->begin();
	if (!notEnd)
	{
		m_2dRenderer->drawText(m_font, "Failed", 400, 400);
		m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);
		m_2dRenderer->end();
	}
	else
	{
		// draw your stuff here!
		m_buttonYellow->Draw(m_2dRenderer);
		m_buttonBlue->Draw(m_2dRenderer);
		m_buttonRed->Draw(m_2dRenderer);
		m_buttonGreen->Draw(m_2dRenderer);
		m_startButton->Draw(m_2dRenderer);
		if (notEnd)
		{
			ballDraw();
		}
		// output some text, uses the last used colour
		m_2dRenderer->drawText(m_font, "Press ESC to quit", 0, 0);

		// done drawing sprites
		m_2dRenderer->end();
	}
}