// для столкновений в игре
#include "AllCollisions.hpp"

namespace SoundSonar
{	// конструктор столкновений
	AllCollisions::AllCollisions()
	{

	}
	// переменные для проверки столкновений
	bool AllCollisions::CheckAllCollisions(sf::Sprite spriteOne, sf::Sprite spriteTwo)
	{
		sf::Rect<float> rectOne = spriteOne.getGlobalBounds();
		sf::Rect<float> rectTwo = spriteTwo.getGlobalBounds();
		// проверка столкновения
		if (rectOne.intersects(rectTwo))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// более точные переменные для проверки столкновений
	bool AllCollisions::CheckAllCollisions(sf::Sprite spriteOne, float scaleOne, sf::Sprite spriteTwo, float scaleTwo)
	{
		spriteOne.setScale(scaleOne, scaleOne);
		spriteTwo.setScale(scaleTwo, scaleTwo);
		sf::Rect<float> rectOne = spriteOne.getGlobalBounds();
		sf::Rect<float> rectTwo = spriteTwo.getGlobalBounds();
		// проверка столкновения
		if (rectOne.intersects(rectTwo))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}
