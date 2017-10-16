#pragma once

#include "Core\Core_types.h"

#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class AState {

private:	
	// VARIABLES //

	const typeStateID _mStateID;

	float _mElapsedTime;
	float _mPausedTime;

	sf::Clock _mElapsedClock;
	sf::Clock _mPausedClock;

	bool _mInit;
	bool _mPaused;
	bool _mCleanup;

	// METHODS //
protected:

	virtual void HandleCleanup(void) = 0;

public:

	AState(const typeStateID stateId);
	virtual ~AState();

	const typeStateID GetStateID(void) const;

	virtual void Init(void);
	virtual void ReInit(void) = 0;
	void DeInit(void);

	bool IsInitComplete();

	virtual void Pause(void);
	virtual void Resume(void);

	bool IsPaused();

	virtual void HandleEvents(void) = 0;
	virtual void UpdateFixed(void) = 0;
	virtual void UpdateVariable(float elapsedTime) = 0;
	virtual void Draw(void) = 0;

	float GetElapsedTime(void) const;

	void Cleanup(void);
};