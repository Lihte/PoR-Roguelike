#pragma once
#include "Core/Entities/Player.h"
#include "Core/Interfaces/Subject.h"

class PlayerController : public Subject{
public:
	PlayerController();
	~PlayerController();

	void updateInput();
private:

};