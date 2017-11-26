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
DungeonGenerator::DungeonGenerator(const int roomCount, TextureHandler* textureHandler)
	: m_pTextureHandler(textureHandler){
	m_RoomCount = roomCount;

	m_MaxRoomWidth = 10;
	m_MaxRoomHeight = 10;
}

DungeonGenerator::~DungeonGenerator(){
}

DungeonGenerator::Tiles DungeonGenerator::GetDungeon(){
	GenerateDungeon();
	m_Tiles = GenerateRoom(100, 100)->tiles;
	return m_Tiles;
}

void DungeonGenerator::GenerateDungeon(){
	for (int i = 0; i < 1; ++i) {
		Room* room = GenerateRoom(0, 0);
		m_Tiles.insert(std::end(m_Tiles), std::begin(room->tiles), std::end(room->tiles));
	}
}

DungeonGenerator::Room* DungeonGenerator::GenerateRoom(int posX, int posY){
	Room* room = new Room;
	const int roomHeight = std::rand() % m_MaxRoomWidth + 7;
	const int roomWidth = std::rand() % m_MaxRoomHeight + 7;
	room->height = roomHeight;
	room->width = roomWidth;

	sf::Vector2f pos(posX, posY);

	for (int i = 0; i < roomHeight; ++i) {
		for (int j = 0; j < roomWidth; ++j) {
			/*if (i == 0 || i == roomHeight - 1
				|| i == 0 || i == roomWidth - 1) {
				room->tiles.push_back(new WallTile(pos, "wall"));
				room->tiles.back()->GetSprite()->setTexture(*m_pTextureHandler->GetReference("wall_brick_brown0"));
			}
			else {*/
				room->tiles.push_back(new FloorTile(pos, "floor"));
				room->tiles.back()->GetSprite()->setTexture(*m_pTextureHandler->GetReference("floor_cobble_blood1"));
			//}
			pos.x += 32;// room->tiles.back()->Getsize();
		}
		pos.y += 32;
		pos.x = posX;
	}

	return room;
}