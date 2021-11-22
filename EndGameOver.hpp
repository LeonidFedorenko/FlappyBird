#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "GameLoop.hpp"

namespace SoundSonar
{
	class EndGameOver : public State
	{	// ���������� ���� (gameover)
	public:
		EndGameOver(GameBirdDataRef data, int score);

		void Init();

		void HandleInput();

		void Update(float dt);

		void Draw(float dt);

	private:
		GameBirdDataRef _data;
		// ��� ��� ���������
		sf::Sprite _background;
		sf::Sprite _titleGameOver; // ���������
		sf::Sprite _bodyScoreContainer; // ����������
		sf::Sprite _retryPlayButton; // ������ "������"
		sf::Sprite _medalPlayer; // ������ �� ���������
		// ��� �������� ����� � ����������� (����� �� �����)
		sf::Text _scorePlayer; // ������� �����     
		sf::Text _HighScorePlayer; // ������ ���������  
		// ��� �������� ����� � ����������� (����������)
		int _score; // ���� �������� �����     
		int _highScorePlay; // ���� - ������ ���������  
	};
}