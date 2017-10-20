#pragma once

#include "SplashScreen.h"

SplashScreen::SplashScreen(const typeAssetID splashID, Game& game, float splashDelay = 10.0f) :
	AScreen(game, SCREEN_SPLASH),
	_mSplashID(splashID),
	_mSplashDelay(splashDelay)
{
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::Init(void)
{
	AScreen::Init();
}

void SplashScreen::ReInit(void)
{
}

void SplashScreen::UpdateFixed(void)
{
	if (false == IsPaused() && GetElapsedTime() > _mSplashDelay)
	{
		//mGame.mScreenManager.RemoveActiveScreen();
	}
}

void SplashScreen::UpdateVariable(float elapsedTime) 
{
}

void SplashScreen::Draw(void) 
{
	//mGame.mWindow.draw(mSplashSprite);
}

void SplashScreen::HandleCleanup(void) 
{
}
