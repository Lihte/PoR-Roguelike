#include "Core/Game.h"

int main()
{
	int exitCode = 0;

	Game* game = new Game("");

	exitCode = game->Run();

	delete game;

	game = NULL;

	return exitCode;
}
