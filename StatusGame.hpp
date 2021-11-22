#pragma once
#include <SFML/Graphics.hpp> // �������
#include "State.hpp" // ��������� ����
#include <SFML/Audio.hpp> // �����
#include "GameLoop.hpp" // ����
#include "BlockPipe.hpp" // �����
#include "LandGame.hpp" // �����
#include "AnimationBird.hpp" // �������� �����
#include "AllCollisions.hpp" // ������������
#include "GlossFlashSpeed.hpp" // �������
#include "DisplayPlayerScore.hpp" // ����� ����������

namespace SoundSonar
{	// ������� ������
	class StatusGame : public State
	{
	public:
		StatusGame(GameBirdDataRef data);

		void Init();

		void HandleInput();

		void Update(float dt);

		void Draw(float dt);

	private:
		GameBirdDataRef _data;
		// ��� ����
		sf::Sprite _background;
		// �����������
		BlockPipe *blockPipe;
		// ������� ����������� - �����
		GameLand *gameLand;
		// ������
		frameBird *fBird;
		// ������� ������� ��� ������������
		GlossFlashSpeed* glossFlashSpeed;
		// ������� ��������� �� ����
		DisplayPlayerScore* displayPlayerScore;
		// ������������
		AllCollisions allCollisions;
		// ��� ������� ��������� ������ �����������
		sf::Clock clock;
		// ����� � ����
		sf::SoundBuffer _hitWavBuffer;
		sf::SoundBuffer _completeWavBuffer;
		sf::SoundBuffer _pointWavBuffer;
		sf::SoundBuffer _wingWavBuffer;
		sf::Sound _hitWav;
		sf::Sound _completeWav;
		sf::Sound _pointWav;
		sf::Sound _wingWav;
		// ���������� �������
		int _gameState;
		// ���������� ��� �������� ����������
		int _score;
	};
}