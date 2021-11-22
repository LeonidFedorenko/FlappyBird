#pragma once
#include <SFML/Graphics.hpp>

// реакция на левую кнопку мыши
namespace SoundSonar
{
	class ManagerInput
	{
	public:
		ManagerInput() {}
		~ManagerInput() {}
		// для регистрации нажатий кнопок мыши
		bool IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window);
		// получаю позицию мыши-курсора (относительно окна)
		sf::Vector2i GetMousePosition(sf::RenderWindow &window);
	};
}