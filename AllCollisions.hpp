#pragma once
// ��� ������������ � ����
#include <SFML/Graphics.hpp>

namespace SoundSonar
{
	class AllCollisions
	{
	public: // ����������
		AllCollisions();
		bool CheckAllCollisions(sf::Sprite sprite1, sf::Sprite sprite2);
		// �������� ���������� ��� ������������
		bool CheckAllCollisions(sf::Sprite sprite1, float scaleOne, sf::Sprite sprite2, float scaleTwo);
	};
}