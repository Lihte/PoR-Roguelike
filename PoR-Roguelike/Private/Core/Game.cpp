#include <Core/Game.h>

Game::Game() : Game("PoR-Roguelike")
{

}

Game::Game(const std::string title) : mTitle(title),
	mWindow(),
	mWindowStyle(sf::Style::Close | sf::Style::Resize),
	mContextSettings(),
	_mExitCode(0),
	_mIsRunning(false)
{
	//gGame = this;
}

int Game::Run(void)
{
	_mIsRunning = true;

	InitRenderer();

	GameLoop();

	Cleanup();

	_mIsRunning = false;

	return _mExitCode;
}

void Game::GameLoop(void)
{

//	sf::Clock updateClock;
//
//	sf::Clock frameClock;
//
//	updateClock.restart();
//
//	sf::Int32 updateNext = updateClock.getElapsedTime().asMilliseconds();

	while (IsRunning() && mWindow.isOpen())
	{
		ProcessInput();

		sf::Event event;
		while (mWindow.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				mWindow.close();
		}

		mWindow.clear();

		mWindow.display();
	}
}

bool Game::IsRunning(void) const 
{
	return _mIsRunning;
}

void Game::InitRenderer(void)
{
	mWindow.create(sf::VideoMode(800, 600), mTitle, mWindowStyle, mContextSettings);

}

void Game::ProcessInput() 
{

}

void Game::Cleanup(void) 
{

}