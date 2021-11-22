#pragma once
#include <SFML/Graphics.hpp>
#include "DefiningSplashScreen.hpp"
#include "GameLoop.hpp"

// ����� ���������� ����
namespace SoundSonar
{
	class DisplayPlayerScore
	{
	public:
		DisplayPlayerScore(GameBirdDataRef data);
		// ��� ������ �� �����
		void Draw();
		// ��� ���������� ����������� (������� ���������)
		void UpdateScore(int score);

	private:
		GameBirdDataRef _data;
		sf::Text _scoreText; // ��� ����������
	};
}