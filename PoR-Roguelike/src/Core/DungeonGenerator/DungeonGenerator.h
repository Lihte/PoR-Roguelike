#pragma once
#include <SFML/System/Vector2.hpp>
#include "Core/Tiles/Tile.h"
#include "Core/Assets/TextureHandler.h"
#include <vector>

class DungeonGenerator {
public:
	typedef std::vector<Tile*> Tiles;

	struct Room {
		Tiles tiles;
		int height;
		int width;
	};

	DungeonGenerator(const int roomCount, TextureHandler* textureHandler);
	~DungeonGenerator();

	Tiles GetDungeon();

private:
	void GenerateDungeon();
	Room* GenerateRoom(int posX, int posY);

	int m_RoomCount;
	int m_MaxRoomHeight;
	int m_MaxRoomWidth;
	Tiles m_Tiles;
	TextureHandler* m_pTextureHandler;
};