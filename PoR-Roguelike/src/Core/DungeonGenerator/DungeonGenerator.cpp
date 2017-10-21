#include "DungeonGenerator.h"
#include <random>

#include "Core/Tiles/Tile.h"

DungeonGenerator::DungeonGenerator(const int roomCount){
	m_RoomCount = roomCount;
}

DungeonGenerator::~DungeonGenerator(){
}

void DungeonGenerator::GenerateRooms(){
	int roomCount = 0;
	while (roomCount <= m_RoomCount) {
		const int roomHeight = std::rand() % m_MaxRoomWidth + 1;
		const int roomWidth = std::rand() % m_MaxRoomHeight + 1;

		for (int i = 0; i < roomHeight; ++i) {
			//m_Tiles.push_back
		}
	}
}