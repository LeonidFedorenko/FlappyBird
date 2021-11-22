#include "LandGame.hpp"
#include "DefiningSplashScreen.hpp"
#include "AllCollisions.hpp"

namespace SoundSonar
{
	GameLand::GameLand(GameBirdDataRef data) : _data(data)
	{	// для получения рисунка земли
		sf::Sprite sprite(_data->assetcontrols.GetTexture("LandGame"));
		sf::Sprite sprite2(_data->assetcontrols.GetTexture("LandGame"));
		// для позиции в окне
		sprite.setPosition(0, _data->window.getSize().y - sprite.getGlobalBounds().height);
		// позиция за первым рисунком
		sprite2.setPosition(sprite.getGlobalBounds().width, _data->window.getSize().y - sprite.getGlobalBounds().height);
		// чередую спрайты
		_gameLandSprites.push_back(sprite);
		_gameLandSprites.push_back(sprite2);
	}

	void GameLand::MoveGameLand(float dt)
	{	// для движения картинки земли
		for (unsigned short int i = 0; i < _gameLandSprites.size(); i++)
		{
			float movement = PIPE_MOVEMENT_SPEED * dt;
			_gameLandSprites.at(i).move( -movement, 0.0f );
			// проверка движения рисунка (по ширине рисунка)
			if (_gameLandSprites.at(i).getPosition().x < 0 - _gameLandSprites.at(i).getGlobalBounds().width)
			{
				sf::Vector2f position(_data->window.getSize().x, _gameLandSprites.at(i).getPosition().y);
				_gameLandSprites.at(i).setPosition(position);
			}
		}
	}

	void GameLand::DrawingGameLand()
	{	// рисую поверхность (рисунок поля из ресурсов)
		for (unsigned short int i = 0; i < _gameLandSprites.size(); i++)
		{
			_data->window.draw(_gameLandSprites.at(i));
		}
	}

	// для столкновений
	const std::vector<sf::Sprite> &GameLand::GetSprites() const
	{	// с поверхностью в игре
		return _gameLandSprites;
	}
}