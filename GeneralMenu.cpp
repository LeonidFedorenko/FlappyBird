#include "GeneralMenu.hpp"
#include "DefiningSplashScreen.hpp"
#include "StatusGame.hpp"
#include <iostream>

namespace SoundSonar
{
	GeneralMenu::GeneralMenu(GameBirdDataRef data) : _data(data)
	{	}
	// ������������� ��������
	void GeneralMenu::Init()
	{
		// ������ ���� � ��������� WINDOW_TITLE
		sf::Window window;
		// ������� ������� ���� (������������ �������� �����)
		window.setPosition(sf::Vector2i(0, 50));
		// ������� ����������� ��� ������������ ������� handle ���� ����� ��������������� ����, 
		// ������� SFML �� ������������
		sf::WindowHandle handle = window.getSystemHandle();
		window.setTitle("����");
		// �������� ������� ��� ���� �������� ���� �� ��������
		_data->assetcontrols.LoadTextureImage("Main Menu Background",
			MAIN_MENU_BACKGROUND_FILEPATH);
		// �������� ������� ��� ��������� �������� ���� �� ��������
		_data->assetcontrols.LoadTextureImage("Game Title",
			GAME_TITLE_FILEPATH);
		// �������� ������� ��� ������ "������" �� ��������
		_data->assetcontrols.LoadTextureImage("Play Button",
			PLAY_BUTTON_FILEPATH);
		// ������������ ������ �������
		_background.setTexture(this->_data->assetcontrols.GetTexture("Main Menu Background"));
		// ������������ ������ �������
		_title.setTexture(this->_data->assetcontrols.GetTexture("Game Title"));
		// ������������ ������ �������
		_playButton.setTexture(this->_data->assetcontrols.GetTexture("Play Button"));
		// ������� �� ������ ��������� � ������
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
			{	// �������� ����
				_data->window.close();
			}
			// ������� ������ "������"
			if (_data->input.IsSpriteClicked(_playButton, sf::Mouse::Left, _data->window))
			{	// �������� ������� ����� ������� std::cout << "������ ����!" << std::endl;
				_data->mashinegame.AddState(StateRef(new StatusGame(_data)), true);
			}
		}
	}

	void GeneralMenu::Update(float dt)
	{		}

	void GeneralMenu::Draw(float dt)
	{	// ���� ����
		_data->window.clear();
		// ����� ���-�������� (������� �� ��������)
		_data->window.draw(_background);
		// ����� ��������� (������� �� ��������)
		_data->window.draw(_title);
		// ����� ������ (������� �� ��������)
		_data->window.draw(_playButton);
		// ��������� �� ������
		_data->window.display();
	}
}