#include "GameScreen.h"
#include "Core\Game.h"
#include "Core\Assets\TextureHandler.h"



GameScreen::GameScreen(Game &game) :
	AScreen(game, SCREEN_GAME)
{
	player = new Player();
	TextureHandler* textureHandler = static_cast<TextureHandler*
>(game.m_AssetManager.GetHandler("TextureHandler"));

	sf::Texture* texture = textureHandler->GetReference("player_placeholder");

	player->GetSprite()->setTexture(*texture);
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
	m_Game.m_Window.draw(*player->GetSprite());
}

void GameScreen::HandleCleanup(void)
{

}