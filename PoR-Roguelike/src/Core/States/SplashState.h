#pragma once

#include "AState.h"

class SplashState : AState
{
	///The Asset ID to assign to the splash image
	typeAssetID	_mSplashID;
	/// The filename of the splash image to load
	//std::string _mSplashFilename;
	/// Splash ImageAsset to load
	//ImageAsset _mSplashImage;
	/// The sprite to hold the splash image being displayed
	//sf::Sprite _mSplashSprite;
	/// The time in seconds to wait before continuing to next game state
	float _mSplashDelay;

protected:

	void HandleCleanup(void);

public:

	SplashState(const typeAssetID splashID, float splashDelay);

	~SplashState();

	virtual void Init(void);

	virtual void ReInit(void);

	virtual void UpdateFixed(void);

	virtual void UpdateVariable(float elapsedTime);

	virtual void Draw(void);
};