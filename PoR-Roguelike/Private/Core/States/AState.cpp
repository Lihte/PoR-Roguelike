#pragma once

#include <Core/States/AState.hpp>

AState::AState(const typeStateID stateId) :
	_mStateID(stateId),
	_mElapsedTime(0.0f),
	_mPausedTime(0.0f),
	_mElapsedClock(),
	_mPausedClock(),
	_mInit(false),
	_mPaused(false),
	_mCleanup(false)
{
	// Maybe log something
}

AState::~AState() 
{
	// Maybe log something
}

const typeStateID AState::GetStateID(void) const 
{
	return _mStateID;
}

void AState::Init(void) {

	if (_mCleanup == true)
	{
		HandleCleanup();
	}

	if (_mInit == false)
	{
		_mInit = true;
		_mPaused = false;
		_mElapsedTime = 0.0f;
		_mElapsedClock.restart();
		_mPausedTime = 0.0f;
		_mPausedClock.restart();
	}
}

void AState::DeInit(void)
{
	if (_mInit == true)
	{
		_mCleanup = true;
		_mInit = false;

		_mElapsedTime += _mElapsedClock.getElapsedTime().asSeconds();

		if (_mPaused == true)
		{
			_mPausedTime += _mPausedClock.getElapsedTime().asSeconds();
		}
	}
}

bool AState::IsInitComplete()
{
	return _mInit;
}

bool AState::IsPaused()
{
	return _mPaused;
}

void AState::Pause(void)
{
	if (_mPaused == false)
	{
		_mPaused = true;
		_mPausedClock.restart();
	}
}

void AState::Resume(void)
{
	if (_mPaused == true)
	{
		_mPaused = false;
		_mPausedTime += _mPausedClock.getElapsedTime().asSeconds;
	}
}

void AState::Cleanup(void)
{
	if (_mCleanup == true)
	{
		HandleCleanup();

		_mCleanup = false;
	}
}

float AState::GetElapsedTime(void) const 
{
	float result = _mElapsedClock.getElapsedTime().asSeconds;

	if (_mInit == false)
	{
		result = _mElapsedTime;
	}

	return result;
}