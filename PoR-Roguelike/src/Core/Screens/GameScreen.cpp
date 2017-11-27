#include "GameScreen.h"
#include "Core\Assets\TextureHandler.h"
#include "Core\Factories\EntityFactory.h"


GameScreen::GameScreen(Game &game) :
	AScreen(game, SCREEN_GAME)
{
	EntityFactory factory = EntityFactory(*m_Game.GetAssetManager().GetTextureHandler());

	entityPool.push_back(factory.CreatePlayer("player"));
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
	for (int i = 0; i < entityPool.size(); i++)
	{
		entityPool[i]->Update(elapsedTime);
	}
}

void GameScreen::Draw(void)
{
	for (int i = 0; i < entityPool.size(); i++)
	{
		m_Game.m_Window.draw(entityPool[i]->GetSprite());
	}
}

void GameScreen::HandleCleanup(void)
{

}