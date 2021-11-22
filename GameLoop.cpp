#include "GameLoop.hpp" 
#include "LoadSplashHeader.hpp"

namespace SoundSonar
{
	Game::Game(int width, int height, std::string title)
	{	// ��� ���������� ��������� ������� ������
		srand(time(NULL));
		// ������ ����
		_data->window.create(sf::VideoMode(width, height), title, 
			sf::Style::Close | sf::Style::Titlebar);
		// ��������
		_data->mashinegame.AddState(StateRef(new LoadSplashHeader(this->_data)));
		// ������
		this->Run();
	}

	void Game::Run()
	{	// ���������� ��� ���� (����� � �����������)
		float newGameTime, frameGameTime, interpolation;
		// ��� �������
		float currentTime = this->_clock.getElapsedTime().asSeconds();
		// ���������� ������� � ����
		float accumulatorTime = 0.0f;
		// ���� ������� ����
		while (this->_data->window.isOpen())
		{	// ������ ���� ����� ��������
			this->_data->mashinegame.ProcessStateChanges();
			// ������� ����� ����
			newGameTime = this->_clock.getElapsedTime().asSeconds();
			frameGameTime = newGameTime - currentTime;
			if (frameGameTime > 0.25f)
			{
				frameGameTime = 0.25f;
			}
			currentTime = newGameTime;
			// ��������� ����� ����
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