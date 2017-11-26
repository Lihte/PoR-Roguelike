#include "Game.h"
#include "Screens\GameScreen.h"
#include "Screens\AScreen.h"
#include "Core/Assets/TextureHandler.h"


Game* Game::gGame = NULL;

Game::Game(const std::string title) : 
	m_Title(title),
	m_Window(),
	m_WindowStyle(sf::Style::Close | sf::Style::Resize),
	m_ContextSettings(),
	m_ExitCode(0),
	m_IsRunning(false),
	m_ScreenManager(),
	m_AssetManager()
{
	gGame = this;
}

int Game::Run(void)
{
	m_IsRunning = true;

	InitRenderer();
	InitScreenFactory();

	m_AssetManager.RegisterHandler(new TextureHandler("TextureHandler"));

	GameLoop();

	Cleanup();

	m_IsRunning = false;

	return m_ExitCode;
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

	while (IsRunning() && m_Window.isOpen())
	{
		ProcessInput();

		sf::Event event;
		while (m_Window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				m_Window.close();
		}

		AScreen& screen = m_ScreenManager.GetActiveScreen();

		m_Window.clear();
		screen.Draw();
		m_Window.display();
	}
}

bool Game::IsRunning(void) const 
{
	return m_IsRunning;
}

void Game::InitScreenFactory(void)
{
	m_ScreenManager.AddActiveScreen(new(std::nothrow) GameScreen(*this));
}

void Game::InitRenderer(void)
{
	m_Window.create(sf::VideoMode(800, 600), m_Title, m_WindowStyle, m_ContextSettings);

}

void Game::ProcessInput() 
{

}

void Game::Cleanup(void) 
{

}