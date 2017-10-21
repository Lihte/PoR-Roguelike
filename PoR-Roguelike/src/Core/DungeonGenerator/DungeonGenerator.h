#pragma once
#include <SFML/System/Vector2.hpp>
#include "Core/Tiles/Tile.h"
#include <vector>

class DungeonGenerator {
public:
	typedef std::vector<Tile*> Tiles;

	struct Room {
		Tiles tiles;
		int height;
		int width;
	};

	DungeonGenerator(const int roomCount);
	~DungeonGenerator();

private:
	Room* GenerateRoom(int posX, int posY);

	int m_RoomCount;
	int m_MaxRoomHeight;
	int m_MaxRoomWidth;
	Tiles m_Tiles;
};