#include "GeneralMenu.hpp"
#include "DefiningSplashScreen.hpp"
#include "StatusGame.hpp"
#include <iostream>

namespace SoundSonar
{
	GeneralMenu::GeneralMenu(GameBirdDataRef data) : _data(data)
	{	}
	// инициализирую заставку
	void GeneralMenu::Init()
	{
		// размер окна и заголовок WINDOW_TITLE
		sf::Window window;
		// изменяю позицию окна (относительно рабочего стола)
		window.setPosition(sf::Vector2i(0, 50));
		// получаю специфичный для операционной системы handle окна чтобы имлементировать вещи, 
		// которые SFML не поддерживает
		sf::WindowHandle handle = window.getSystemHandle();
		window.setTitle("Игра");
		// загружаю рисунок для фона главного окна из ресурсов
		_data->assetcontrols.LoadTextureImage("Main Menu Background",
			MAIN_MENU_BACKGROUND_FILEPATH);
		// загружаю рисунок для заголовка главного окна из ресурсов
		_data->assetcontrols.LoadTextureImage("Game Title",
			GAME_TITLE_FILEPATH);
		// загружаю рисунок для кнопки "Играть" из ресурсов
		_data->assetcontrols.LoadTextureImage("Play Button",
			PLAY_BUTTON_FILEPATH);
		// устанавливаю данный рисунок
		_background.setTexture(this->_data->assetcontrols.GetTexture("Main Menu Background"));
		// устанавливаю данный рисунок
		_title.setTexture(this->_data->assetcontrols.GetTexture("Game Title"));
		// устанавливаю данный рисунок
		_playButton.setTexture(this->_data->assetcontrols.GetTexture("Play Button"));
		// позиции на экране заголовка и кнопки
		_title.setPosition((SCREEN_WIDTH / 2) - (_title.getGlobalBounds().width / 2), 
			_title.getGlobalBounds().height / 2);
		_playButton.setPosition((SCREEN_WIDTH / 2) - (_playButton.getGlobalBounds().width / 2),
			(SCREEN_HEIGHT / 2) - (_playButton.getGlobalBounds().height / 2));
	}

	void GeneralMenu::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{	// закрываю окно
				_data->window.close();
			}
			// нажатие кнопки "Играть"
			if (_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window))
			{	// проверяю нажатие через консоль std::cout << "Запуск игры!" << std::endl;
				_data->mashinegame.AddState(StateRef(new StatusGame(_data)), true);
			}
		}
	}

	void GeneralMenu::Update(float dt)
	{		}

	void GeneralMenu::Draw(float dt)
	{	// чищу окно
		_data->window.clear();
		// рисую фон-подложку (рисунок из ресурсов)
		_data->window.draw(_background);
		// рисую заголовок (рисунок из ресурсов)
		_data->window.draw(_title);
		// рисую кнопку (рисунок из ресурсов)
		_data->window.draw(_playButton);
		// показываю на экране
		_data->window.display();
	}
}