#pragma once
// для столкновений в игре
#include <SFML/Graphics.hpp>

namespace SoundSonar
{
	class AllCollisions
	{
	public: // констуктор
		AllCollisions();
		bool CheckAllCollisions(sf::Sprite sprite1, sf::Sprite sprite2);
		// уменьшаю расстояние для столкновения
		bool CheckAllCollisions(sf::Sprite sprite1, float scaleOne, sf::Sprite sprite2, float scaleTwo);
	};
}
