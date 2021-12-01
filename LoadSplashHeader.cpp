#include "LoadSplashHeader.hpp" // заставка
#include "DefiningSplashScreen.hpp"
#include "State.hpp"
#include "GeneralMenu.hpp"
#include <SFML/Audio.hpp> // звуки
#include <iostream>
#include <sstream>

namespace SoundSonar
{
	LoadSplashHeader::LoadSplashHeader(GameBirdDataRef data) : _data(data)
	{	}
	// инициализирую заставку
	void LoadSplashHeader::Init()
	{	// загружаю рисунок заставки из ресурсов
		_data->assetcontrols.LoadTextureImage("Splash State Background", 
			SPLASH_SCENE_BACKGROUND_FILEPATH);
		// устанавливаю данный рисунок
		_background.setTexture(this->_data->assetcontrols.GetTexture("Splash State Background"));
		if (!_completeWavBuffer.loadFromFile(SOUND_COMLETE_FILEPATH))
		{
			std::cout << "ќшибка при загрузке звука!" << std::endl;
		}
		_completeWav.setBuffer(_completeWavBuffer);
		// озвучиваю
		_completeWav.play();
	}

	void LoadSplashHeader::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{	// закрываю окно
				_data->window.close();
			}
		}
	}

	void LoadSplashHeader::Update(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{	// «десь будет переход в меню
			_data->mashinegame.AddState(StateRef(new GeneralMenu(_data)), true);
		}
	}

	void LoadSplashHeader::Draw(float dt)
	{	// чищу окно
		_data->window.clear();
		// рисую подложку (рисунок из ресурсов)
		_data->window.draw(_background);
		// показываю на экране
		_data->window.display();
	}
}
