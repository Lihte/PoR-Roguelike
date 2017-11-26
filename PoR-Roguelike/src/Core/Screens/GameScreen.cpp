#include "GameScreen.h"
#include "Core\Assets\TextureHandler.h"
#include "Core\Factories\EntityFactory.h"


GameScreen::GameScreen(Game &game) :
	AScreen(game, SCREEN_GAME)
{
	TextureHandler* textureHandler = static_cast<TextureHandler*>(m_Game.m_AssetManager.GetHandler("TextureHandler"));

	EntityFactory factory = EntityFactory(m_Game, *textureHandler);

	player = factory.CreatePlayer();
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

void GameScreen::UpdateFixed()
{

	
}

void GameScreen::UpdateVariable(float elapsedTime)
{
	player->Update(elapsedTime);
}

void GameScreen::Draw(void)
{
	m_Game.m_Window.draw(*player->GetSprite());
}

void GameScreen::HandleCleanup(void)
{

}