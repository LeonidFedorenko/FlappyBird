#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameLoop.hpp" // Game.hpp

namespace SoundSonar
{	// ����� � ����
	class GameLand
	{ // ��������� �����
	public:
		GameLand(GameBirdDataRef data);
		// �������� ����� � ����
		void MoveGameLand(float dt);
		// ���������� ����� � ����
		void DrawingGameLand();
		// ��� ������������
		const std::vector<sf::Sprite> &GetSprites() const;

	private:
		GameBirdDataRef _data;
		std::vector<sf::Sprite>_gameLandSprites;
	};
}