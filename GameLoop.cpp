#include "GameLoop.hpp" 
#include "LoadSplashHeader.hpp"

namespace SoundSonar
{
	Game::Game(int width, int height, std::string title)
	{	// для случайного появления позиций блоков
		srand(time(NULL));
		// создаю окно
		_data->window.create(sf::VideoMode(width, height), title, 
			sf::Style::Close | sf::Style::Titlebar);
		// заставка
		_data->mashinegame.AddState(StateRef(new LoadSplashHeader(this->_data)));
		// запуск
		this->Run();
	}

	void Game::Run()
	{	// переменные для окна (время и сглаживание)
		float newGameTime, frameGameTime, interpolation;
		// для времени
		float currentTime = this->_clock.getElapsedTime().asSeconds();
		// накопление времени в игре
		float accumulatorTime = 0.0f;
		// пока открыто окно
		while (this->_data->window.isOpen())
		{	// статус игры может меняться
			this->_data->mashinegame.ProcessStateChanges();
			// засекаю время игры
			newGameTime = this->_clock.getElapsedTime().asSeconds();
			frameGameTime = newGameTime - currentTime;
			if (frameGameTime > 0.25f)
			{
				frameGameTime = 0.25f;
			}
			currentTime = newGameTime;
			// прибавляю время игры
			accumulatorTime += frameGameTime;
			while (accumulatorTime >= dt)
			{
				this->_data->mashinegame.GetActivateState()->HandleInput();
				this->_data->mashinegame.GetActivateState()->Update(dt);
				accumulatorTime -= dt;
			}
			interpolation = accumulatorTime / dt;
			this->_data->mashinegame.GetActivateState()->Draw(interpolation);
		}
	}
}