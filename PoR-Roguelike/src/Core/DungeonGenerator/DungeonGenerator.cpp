#include "DungeonGenerator.h"
#include <random>

#include "Core/Tiles/FloorTile.h"
#include "Core/Tiles/WallTile.h"
#include "Core/Tiles/Tile.h"
#include "Core/GameObject.h"

/* TODO:

	Create n rooms
	Move the rooms out untill there is no collision anywhere
	Create corridors to connect all rooms

*/
DungeonGenerator::DungeonGenerator(const int roomCount){
	m_RoomCount = roomCount;
}

DungeonGenerator::~DungeonGenerator(){
}

DungeonGenerator::Room* DungeonGenerator::GenerateRoom(int posX, int posY){
	Room* room = new Room;
	const int roomHeight = std::rand() % m_MaxRoomWidth + 1;
	const int roomWidth = std::rand() % m_MaxRoomHeight + 1;
	room->height = roomHeight;
	room->width = roomWidth;

	sf::Vector2f pos(posX, posY);

	for (int i = 0; i < roomHeight; ++i) {
		for (int j = 0; j < roomWidth; ++j) {
			if (i == 0 || i == roomHeight - 1
				|| i == 0 || i == roomWidth - 1)
				room->tiles.push_back(new WallTile(pos, "wall"));
			else
				room->tiles.push_back(new FloorTile(pos, "floor"));
			pos += room->tiles.back()->Getsize();
		}
	}

	return room;
}