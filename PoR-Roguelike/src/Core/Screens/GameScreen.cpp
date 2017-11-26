#include "GameScreen.h"
#include "Core\Game.h"
#include "Core\Assets\TextureHandler.h"
#include "Core/Tiles/Tile.h"
#include "Core/Tiles/FloorTile.h"
#include "Core/Tiles/WallTile.h"
#include "Core/DungeonGenerator/DungeonGenerator.h"

GameScreen::GameScreen(Game &game) :
	AScreen(game, SCREEN_GAME)
{
	TextureHandler* textureHandler = static_cast<TextureHandler*
>(game.m_AssetManager.GetHandler("TextureHandler"));

	DungeonGenerator dg(1, textureHandler);
	m_Tiles = dg.GetDungeon();

	//sf::Texture* texture = textureHandler->GetReference("floor_cobble_blood1");
	//m_Tiles.push_back(new FloorTile(sf::Vector2f(100, 100), "FloorTile"));
	//m_Tiles.back()->GetSprite()->setTexture(*texture);
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
	for (auto it : m_Tiles) {
		it->Update(1);
	}
}

void GameScreen::UpdateVariable(float elapsedTime)
{

}

void GameScreen::Draw(void)
{
	for (auto it : m_Tiles) {
		m_Game.m_Window.draw(*it->GetSprite());
	};
}

void GameScreen::HandleCleanup(void)
{

}