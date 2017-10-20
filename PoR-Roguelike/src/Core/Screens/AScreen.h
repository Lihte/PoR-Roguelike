#pragma once

#include "Core\Core_types.h"

#include <SFML\Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>

class AScreen {

public:

	AScreen(Game& game, const ScreenType screenId);
	virtual ~AScreen();

	const ScreenType GetScreenID(void) const;

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

protected:

	virtual void HandleCleanup(void) = 0;

	Game& m_Game;

private:

	// VARIABLES //

	const ScreenType m_ScreenID;

	float m_ElapsedTime;
	float m_PausedTime;

	sf::Clock m_ElapsedClock;
	sf::Clock m_PausedClock;

	bool m_Init;
	bool m_Paused;
	bool m_Cleanup;
};