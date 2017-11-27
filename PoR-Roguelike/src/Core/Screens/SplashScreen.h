#pragma once

#include "AScreen.h"

class SplashScreen : public AScreen
{
public:

	SplashScreen(Game& game, const typeAssetID splashID = "SplashScreen", float splashDelay = 10.0F);

	~SplashScreen();

	virtual void Init(void);

	virtual void ReInit(void);

	virtual void HandleEvents(void);

	virtual void UpdateFixed(void);

	virtual void UpdateVariable(float elapsedTime);

	virtual void Draw(void);
	

protected:
	void HandleCleanup(void);

private:
	///The Asset ID to assign to the splash image
	typeAssetID	m_SplashID;
	/// The sprite to hold the splash image being displayed
	sf::Sprite m_SplashSprite;
	/// The time in seconds to wait before continuing to next game Screen
	float _mSplashDelay;
};