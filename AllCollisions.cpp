// äëÿ ñòîëêíîâåíèé â èãðå 
#include "AllCollisions.hpp"

namespace SoundSonar
{	// êîíñòðóêòîð ñòîëêíîâåíèé
	AllCollisions::AllCollisions()
	{

	}
	// ïåðåìåííûå äëÿ ïðîâåðêè ñòîëêíîâåíèé
	bool AllCollisions::CheckAllCollisions(sf::Sprite spriteOne, sf::Sprite spriteTwo)
	{
		sf::Rect<float> rectOne = spriteOne.getGlobalBounds();
		sf::Rect<float> rectTwo = spriteTwo.getGlobalBounds();
		// ïðîâåðêà ñòîëêíîâåíèÿ
		if (rectOne.intersects(rectTwo))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// áîëåå òî÷íûå ïåðåìåííûå äëÿ ïðîâåðêè ñòîëêíîâåíèé
	bool AllCollisions::CheckAllCollisions(sf::Sprite spriteOne, float scaleOne, sf::Sprite spriteTwo, float scaleTwo)
	{
		spriteOne.setScale(scaleOne, scaleOne);
		spriteTwo.setScale(scaleTwo, scaleTwo);
		sf::Rect<float> rectOne = spriteOne.getGlobalBounds();
		sf::Rect<float> rectTwo = spriteTwo.getGlobalBounds();
		// ïðîâåðêà ñòîëêíîâåíèÿ
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
