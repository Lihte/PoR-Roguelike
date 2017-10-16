#pragma once

#include <Core/Core_types.hpp>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class AState {

	/// The State ID
	const typeStateID _mStateID;
	/// Total elapsed time since DoInit was called
	float _mElapsedTime;
	/// Total elapsed time paused since DoInit was called
	float _mPausedTime;
	/// Clock to keep track of running and paused elapsed time
	sf::Clock _mElapsedClock;
	/// Clock to keep track of time paused
	sf::Clock _mPausedClock;
	/// Boolean that indicates that DoInit has been called
	bool _mInit;
	/// State is currently paused (not active)
	bool _mPaused;
	/// State needs to be cleaned up at the end of the next game loop
	bool _mCleanup;

protected:

	virtual void HandleCleanup(void) = 0;

public:

	/**
	* AState constructor
	* @param[in] stateId to use for this State object
	*/
	AState(const typeStateID stateId);

	virtual ~AState();

	const typeStateID GetStateID(void) const;

	virtual void Init(void);

	virtual void ReInit(void) = 0;

	void DeInit(void);

	bool IsInitComplete();

	bool IsPaused();

	virtual void Pause(void);

	virtual void Resume(void);

	virtual void UpdateFixed(void) = 0;

	virtual void UpdateVariable(float elapsedTime) = 0;

	virtual void Draw(void) = 0;

	void Cleanup(void);

	float GetElapsedTime(void) const;
};