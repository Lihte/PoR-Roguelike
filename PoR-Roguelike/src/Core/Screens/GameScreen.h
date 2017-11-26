#pragma once
#include "AScreen.h"
#include "Core\Entities\Player.h"

class Tile;

class GameScreen : public AScreen
{
public:
	typedef std::vector<Tile*> TileVector;

	GameScreen(Game &game);
	virtual ~GameScreen();

	virtual void ReInit(void);

	virtual void HandleEvents(void);
	virtual void UpdateFixed(void);
	virtual void UpdateVariable(float elapsedTime);
	virtual void Draw(void);

protected:
	virtual void HandleCleanup(void);

private:

	TileVector m_Tiles;
	Player* player;
};

