#include <SFML/Graphics.hpp>
#include "Managers\ScreenManager.h"
#include "Managers\AssetManager.h"

class Game {

public:

	Game(const std::string title);

	bool IsRunning(void) const;

	int Run(void);

	void Quit(int theExitCode);

	std::string m_Title;

	unsigned long m_WindowStyle;

	sf::ContextSettings m_ContextSettings;

	sf::RenderWindow m_Window;

	ScreenManager m_ScreenManager;
	AssetManager m_AssetManager;

protected:

	void GameLoop(void);

	void ProcessInput(AScreen& screen);

	void Cleanup(void);

private:

	void InitRenderer(void);

	void InitScreenFactory(void);

	bool m_IsRunning;

	int m_ExitCode;

	static Game* gGame;

	sf::Int32 m_UpdateRate;

	uint32_t m_MaxUpdates;
};