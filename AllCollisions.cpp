// ��� ������������ � ����
#include "AllCollisions.hpp"

namespace SoundSonar
{	// ����������� ������������
	AllCollisions::AllCollisions()
	{

	}
	// ���������� ��� �������� ������������
	bool AllCollisions::CheckAllCollisions(sf::Sprite spriteOne, sf::Sprite spriteTwo)
	{
		sf::Rect<float> rectOne = spriteOne.getGlobalBounds();
		sf::Rect<float> rectTwo = spriteTwo.getGlobalBounds();
		// �������� ������������
		if (rectOne.intersects(rectTwo))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	// ����� ������ ���������� ��� �������� ������������
	bool AllCollisions::CheckAllCollisions(sf::Sprite spriteOne, float scaleOne, sf::Sprite spriteTwo, float scaleTwo)
	{
		spriteOne.setScale(scaleOne, scaleOne);
		spriteTwo.setScale(scaleTwo, scaleTwo);
		sf::Rect<float> rectOne = spriteOne.getGlobalBounds();
		sf::Rect<float> rectTwo = spriteTwo.getGlobalBounds();
		// �������� ������������
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