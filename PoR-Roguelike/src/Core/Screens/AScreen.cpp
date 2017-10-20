#pragma once

#include "AScreen.h"
#include "Core/Game.h"

AScreen::AScreen(Game& game, const ScreenType ScreenId) :
	m_Game(game),
	m_ScreenID(ScreenId),
	m_ElapsedTime(0.0f),
	m_PausedTime(0.0f),
	m_ElapsedClock(),
	m_PausedClock(),
	m_Init(false),
	m_Paused(false),
	m_Cleanup(false)
{
	// Maybe log something
}

AScreen::~AScreen() 
{
	// Maybe log something
}

const ScreenType AScreen::GetScreenID(void) const
{
	return m_ScreenID;
}

void AScreen::Init(void) {

	if (m_Cleanup == true)
	{
		HandleCleanup();
	}

	if (m_Init == false)
	{
		m_Init = true;
		m_Paused = false;
		m_ElapsedTime = 0.0f;
		m_ElapsedClock.restart();
		m_PausedTime = 0.0f;
		m_PausedClock.restart();
	}
}

void AScreen::DeInit(void)
{
	if (m_Init == true)
	{
		m_Cleanup = true;
		m_Init = false;

		m_ElapsedTime += m_ElapsedClock.getElapsedTime().asSeconds();

		if (m_Paused == true)
		{
			m_PausedTime += m_PausedClock.getElapsedTime().asSeconds();
		}
	}
}

bool AScreen::IsInitComplete()
{
	return m_Init;
}

void AScreen::Pause(void)
{
	if (m_Paused == false)
	{
		m_Paused = true;
		m_PausedClock.restart();
	}
}

void AScreen::Resume(void)
{
	if (m_Paused == true)
	{	
		m_Paused = false;
		m_PausedTime += m_PausedClock.getElapsedTime().asSeconds();
	}
}

bool AScreen::IsPaused()
{
	return m_Paused;
}

float AScreen::GetElapsedTime(void) const
{
	float result = m_ElapsedClock.getElapsedTime().asSeconds();

	if (m_Init == false)
	{
		result = m_ElapsedTime;
	}

	return result;
}

void AScreen::Cleanup(void)
{
	if (m_Cleanup == true)
	{
		HandleCleanup();

		m_Cleanup = false;
	}
}