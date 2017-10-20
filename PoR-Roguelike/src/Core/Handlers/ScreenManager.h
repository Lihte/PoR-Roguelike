#pragma once

#include <unordered_map>
#include <memory>

#include "Core\Screens\AScreen.h"
#include "Core\Core_types.h"

class ScreenManager {
	
	AScreen* m_pActiveScreen;

	std::unordered_map<ScreenType, AScreen*> m_ScreenMap;

protected:

	Game* m_Game;

public:

	ScreenManager();

	virtual ~ScreenManager();

	bool IsEmpty(void);

	void AddActiveScreen(AScreen* screen);

	void AddInactiveScreen(AScreen* screen);

	AScreen& GetActiveScreen(void);

	void InactivateActiveScreen(void);

	void DropActiveScreen(void);

	void ResetActiveScreen(void);

	void RemoveActiveScreen(void);

	void SetActiveScreen(ScreenType screenId);

	void Cleanup(void);
};