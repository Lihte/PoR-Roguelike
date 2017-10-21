#pragma once
#include <SFML/System/Vector2.hpp>
#include <vector>

class Tiles;

class DungeonGenerator {
public:
	DungeonGenerator();
	~DungeonGenerator();

private:
	std::vector<Tiles> TileTypes;
};