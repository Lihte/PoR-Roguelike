#include <SFML/Graphics.hpp>

class Game {

	bool _mIsRunning;

	int _mExitCode;

	//static Game* gGame;

	void InitRenderer(void);

protected:

	Game(const std::string title);

	void GameLoop(void);

	void ProcessInput();

	void Cleanup(void);

public:

	Game();

	std::string mTitle;

	unsigned long mWindowStyle;

	sf::ContextSettings mContextSettings;

	sf::RenderWindow mWindow;


	bool IsRunning(void) const;

	int Run(void);
};