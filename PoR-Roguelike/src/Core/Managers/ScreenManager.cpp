#include <assert.h>
#include <memory>

#include "Core\Game.h"
#include "ScreenManager.h"

ScreenManager::ScreenManager() {

}

ScreenManager::~ScreenManager() {

}

void ScreenManager::AddActiveScreen(AScreen* screen)
{
	assert(screen != NULL && "ScreenManager::AddActiveScreen() received a bad pointer");

	InactivateActiveScreen();

	// Add new Screen to the map
	m_ScreenMap[screen->GetScreenID()] = screen;

	// Initialize the new Screen
	screen->Init();

	// Set new Screen as active
	m_pActiveScreen = screen;
}

void ScreenManager::AddInactiveScreen(AScreen* screen)
{
	// Check that they didn't provide a bad pointer
	assert(NULL != screen && "ScreenManager::AddInactiveScreen() received a bad pointer");

	// Add the inactive Screen to the map
	m_ScreenMap[screen->GetScreenID()] = screen;
}

AScreen& ScreenManager::GetActiveScreen(void) {
	return *m_pActiveScreen;
}

void ScreenManager::InactivateActiveScreen(void)
{
	if (m_pActiveScreen != nullptr)
	{
		m_pActiveScreen->Pause();
	}
}

void ScreenManager::SetActiveScreen(ScreenType screenId)
{
	InactivateActiveScreen();

	AScreen* aScreen = m_ScreenMap[screenId];

	if (aScreen->IsInitComplete())
	{
		aScreen->Resume();
	}
	else
	{
		aScreen->Init();
	}

	m_pActiveScreen = aScreen;

	aScreen = nullptr;
}

void ScreenManager::ResetActiveScreen(void)
{
	if (m_pActiveScreen != nullptr)
	{
		InactivateActiveScreen();

		m_pActiveScreen->ReInit();

		m_pActiveScreen->Resume();
	}
}

bool ScreenManager::IsEmpty(void)
{
	return m_ScreenMap.empty();
}

void ScreenManager::DropActiveScreen(void)
{
	if (m_pActiveScreen != nullptr)
	{
		InactivateActiveScreen();

		m_pActiveScreen->DeInit();

		m_pActiveScreen = nullptr;
	}
}

void ScreenManager::Cleanup(void)
{

}