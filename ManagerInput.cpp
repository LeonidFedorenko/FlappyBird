#include "ManagerInput.hpp"

// курсор мыши
namespace SoundSonar
{
	bool ManagerInput::IsSpriteClicked(sf::Sprite object, sf::Mouse::Button button, sf::RenderWindow &window)
	{
		if (sf::Mouse::isButtonPressed(button))
		{	// если нажата клавиша - определяю позицию
			sf::IntRect tempRect(object.getPosition().x, object.getPosition().y, 
				object.getGlobalBounds().width, object.getGlobalBounds().height);
			// если курсор в пределах окна (проверка)
			if (tempRect.contains(sf::Mouse::getPosition(window)))
			{
				return true;
			}
		}
		// проверка не пройдена
		return false;
	}

	sf::Vector2i ManagerInput::GetMousePosition(sf::RenderWindow &window)
	{	// возвращаю позицию курсора
		return sf::Mouse::getPosition(window);
	}
}
