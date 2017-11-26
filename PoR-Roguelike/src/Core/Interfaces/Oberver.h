#pragma once
#include <vector>

enum Event {
	Action_Jump
	, Action_MoveUP
	, Action_MoveDown
	, Action_MoveLeft
	, Action_MoveRight
};

class IObserver {
public:
	virtual ~IObserver() {}
	virtual void onNotify(Event event) = 0;
};