#include "GlossFlashSpeed.hpp"

namespace SoundSonar
{
	GlossFlashSpeed::GlossFlashSpeed(GameBirdDataRef data) : _data(data)
	{	// �� ��� ������� ����
		_shape = sf::RectangleShape(sf::Vector2f(_data->window.getSize()));
		// ������ ���� �������
		_shape.setFillColor(sf::Color(255, 0, 0, 0));  // �������
		// �� ��������� �������� �������
		_glossFlashON = true;
	}

	// ����� ��������������� �������
	void GlossFlashSpeed::Show(float dt)
	{	// �������� ��������� �� �������
		if (_glossFlashON)
		{
			int alpha = (int)_shape.getFillColor().a + (GLOSS_FLASH_SPEED * dt);
			if (alpha >= 255.0f)
			{
				alpha = 255.0f;
				_glossFlashON = false; // ��������
			}
			_shape.setFillColor(sf::Color(255, 0, 0, alpha));
		}
		else
		{
			int alpha = (int)_shape.getFillColor().a - (GLOSS_FLASH_SPEED * dt);
			if (alpha <= 0.0f)
			{
				alpha = 0.0f;
				_glossFlashON = false; // ��������
			}
			_shape.setFillColor(sf::Color(255, 0, 0, alpha));
		}
	}

	// ����� ��� ����������
	void GlossFlashSpeed::Draw()
	{
		_data->window.draw(_shape);
	}
}