#pragma once
#include "Core/Game.h"
#include "Core\Assets\TextureHandler.h"
#include "SplashScreen.h"

SplashScreen::SplashScreen(Game& game, const typeAssetID splashID, float splashDelay) :
	AScreen(game, SCREEN_SPLASH),
	m_SplashID(splashID),
	_mSplashDelay(splashDelay)
{
}

SplashScreen::~SplashScreen()
{
}

void SplashScreen::Init(void)
{
	AScreen::Init();
	m_SplashSprite.setTexture(*m_Game.GetAssetManager().GetTextureHandler()->GetReference(m_SplashID));
}

void SplashScreen::ReInit(void)
{
}

void SplashScreen::HandleEvents(void)
{

}

void SplashScreen::UpdateFixed(void)
{
	if (false == IsPaused() && GetElapsedTime() > _mSplashDelay)
	{
		m_Game.GetScreenManager().DropActiveScreen();
		m_Game.GetScreenManager().SetActiveScreen(SCREEN_GAME);
	}
}

void SplashScreen::UpdateVariable(float elapsedTime) 
{
}

void SplashScreen::Draw(void) 
{
	m_Game.m_Window.draw(m_SplashSprite);
}

void SplashScreen::HandleCleanup(void) 
{
}
