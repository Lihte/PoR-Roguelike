#include "GameScreen.h"
#include "Core\Game.h"



GameScreen::GameScreen(Game &game) :
	AScreen(game, SCREEN_GAME),
	shape(100.f)
{
	shape.setFillColor(sf::Color::Green);
}

GameScreen::~GameScreen()
{
}

void GameScreen::ReInit(void)
{
}

void GameScreen::HandleEvents(void)
{
}

void GameScreen::UpdateFixed(void)
{

}

void GameScreen::UpdateVariable(float elapsedTime)
{

}

void GameScreen::Draw(void)
{
	m_Game.m_Window.draw(shape);
}

void GameScreen::HandleCleanup(void)
{

}