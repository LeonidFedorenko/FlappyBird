#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "Assets�ontrol.hpp"
#include "GameMashine.hpp"
#include "ManagerInput.hpp"

namespace SoundSonar
{	// ��������� ��� ����
	struct GameBirdData
	{
		GameMashine mashinegame; // ������ ����
		sf::RenderWindow window; // ����
		AssetsControl assetcontrols; // ���, �����
		ManagerInput input; // ����
	};

	typedef std::shared_ptr<GameBirdData> GameBirdDataRef;

	class Game // ����� ��� ����
	{
	public:
		Game(int width, int height, std::string title);
	private:
		// ���������� ����������� �� ��������� 60 � �������
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock; // �����
		// ��� �������� � ������� ����
		GameBirdDataRef _data = std::make_shared<GameBirdData>();
		void Run(); // ������
	};
}