#pragma once

#include <Core\States\SplashState.h>

SplashState::SplashState(const typeAssetID splashID, float splashDelay = 10.0f) :
	AState("Splash"),
	_mSplashID(splashID),
	_mSplashDelay(splashDelay)
{
}

SplashState::~SplashState()
{
}

void SplashState::Init(void)
{
	AState::Init();
}

void SplashState::ReInit(void)
{
}

void SplashState::UpdateFixed(void)
{
	if (false == IsPaused() && GetElapsedTime() > _mSplashDelay)
	{
		//mGame.mStateManager.RemoveActiveState();
	}
}

void SplashState::UpdateVariable(float elapsedTime) 
{
}

void SplashState::Draw(void) 
{
	//mGame.mWindow.draw(mSplashSprite);
}

void SplashState::HandleCleanup(void) 
{
}
