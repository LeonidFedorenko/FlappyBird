#include "LoadSplashHeader.hpp" // ��������
#include "DefiningSplashScreen.hpp"
#include "State.hpp"
#include "GeneralMenu.hpp"
#include <SFML/Audio.hpp> // �����
#include <iostream>
#include <sstream>

namespace SoundSonar
{
	LoadSplashHeader::LoadSplashHeader(GameBirdDataRef data) : _data(data)
	{	}
	// ������������� ��������
	void LoadSplashHeader::Init()
	{	// �������� ������� �������� �� ��������
		_data->assetcontrols.LoadTextureImage("Splash State Background", 
			SPLASH_SCENE_BACKGROUND_FILEPATH);
		// ������������ ������ �������
		_background.setTexture(this->_data->assetcontrols.GetTexture("Splash State Background"));
		if (!_completeWavBuffer.loadFromFile(SOUND_COMLETE_FILEPATH))
		{
			std::cout << "������ ��� �������� �����!" << std::endl;
		}
		_completeWav.setBuffer(_completeWavBuffer);
		// ���������
		_completeWav.play();
	}

	void LoadSplashHeader::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{	// �������� ����
				_data->window.close();
			}
		}
	}

	void LoadSplashHeader::Update(float dt)
	{
		if (_clock.getElapsedTime().asSeconds() > SPLASH_STATE_SHOW_TIME)
		{	// ����� ����� ������� � ����
			_data->mashinegame.AddState(StateRef(new GeneralMenu(_data)), true);
		}
	}

	void LoadSplashHeader::Draw(float dt)
	{	// ���� ����
		_data->window.clear();
		// ����� �������� (������� �� ��������)
		_data->window.draw(_background);
		// ��������� �� ������
		_data->window.display();
	}
}