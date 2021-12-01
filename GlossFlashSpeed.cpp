#include "GlossFlashSpeed.hpp"

namespace SoundSonar
{
	GlossFlashSpeed::GlossFlashSpeed(GameBirdDataRef data) : _data(data)
	{	// на всю область окна
		_shape = sf::RectangleShape(sf::Vector2f(_data->window.getSize()));
		// ставлю цвет вспышки
		_shape.setFillColor(sf::Color(255, 0, 0, 0));  // красный
		// по умолчанию разрешаю вспышку
		_glossFlashON = true;
	}

	// метод воспроизведение вспышки
	void GlossFlashSpeed::Show(float dt)
	{	// проверка разрешена ли вспышка
		if (_glossFlashON)
		{
			int alpha = (int)_shape.getFillColor().a + (GLOSS_FLASH_SPEED * dt);
			if (alpha >= 255.0f)
			{
				alpha = 255.0f;
				_glossFlashON = false; // запрещаю
			}
			_shape.setFillColor(sf::Color(255, 0, 0, alpha));
		}
		else
		{
			int alpha = (int)_shape.getFillColor().a - (GLOSS_FLASH_SPEED * dt);
			if (alpha <= 0.0f)
			{
				alpha = 0.0f;
				_glossFlashON = false; // запрещаю
			}
			_shape.setFillColor(sf::Color(255, 0, 0, alpha));
		}
	}

	// метод для прорисовки
	void GlossFlashSpeed::Draw()
	{
		_data->window.draw(_shape);
	}
}
