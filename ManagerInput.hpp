#pragma once
#include <SFML/Graphics.hpp>

// ������� �� ����� ������ ����
namespace SoundSonar
{
	class ManagerInput
	{
	public:
		ManagerInput() {}
		~ManagerInput() {}
		// ��� ����������� ������� ������ ����
		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
		// ������� ������� ����-������� (������������ ����)
		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	};
}