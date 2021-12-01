#include "AnimationBird.hpp"

namespace SoundSonar
{
	frameBird::frameBird(GameBirdDataRef data) : _data(data)
	{	// анимаци¤ птицы
		_animationIterator = 0;
		// 4 кадра анимации птицы
		_animationFrames.push_back(_data->assetcontrols.GetTexture("Bird Frame_1"));
		_animationFrames.push_back(_data->assetcontrols.GetTexture("Bird Frame_2"));
		_animationFrames.push_back(_data->assetcontrols.GetTexture("Bird Frame_3"));
		_animationFrames.push_back(_data->assetcontrols.GetTexture("Bird Frame_4"));
		// обращаюсь к ресурсам дл¤ получени¤ рисунков
		_fBirdSprite.setTexture(_animationFrames.at(_animationIterator));
		// дл¤ изменени¤ позиции птицы (в полЄте)
		_fBirdSprite.setPosition(
			(_data->window.getSize().x / 4) - (_fBirdSprite.getGlobalBounds().width / 2),
			(_data->window.getSize().y / 2) - (_fBirdSprite.getGlobalBounds().height / 2));
		_birdState = BIRD_ONE_STILL;
		// дл¤ смены угла-направлени¤ полЄта
		sf::Vector2f origin = sf::Vector2f(_fBirdSprite.getGlobalBounds().width / 2,
			_fBirdSprite.getGlobalBounds().height / 2); // мен¤ю
		_fBirdSprite.setOrigin(origin); // ставлю угол
		_flightAngle = 0;
	}

	void frameBird::Draw()
	{	// прорисовка птицы
		_data->window.draw(_fBirdSprite);
	}

	// анимаци¤ кадров дл¤ птицы
	void frameBird::AnimateBird(float dt)
	{	// провер¤ю нужно ли мен¤ть кадр дл¤ птицы
		if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size())
		{	// врем¤ кадра указываю в файле DefiningSplashScreen.hpp
			if (_animationIterator < _animationFrames.size() - 1)
			{
				_animationIterator++;
			}
			else
			{
				_animationIterator = 0;
			}
			// мен¤ю рисунок-текстуру птицы
			_fBirdSprite.setTexture(_animationFrames.at(_animationIterator));
			_clock.restart(); // перезапуск таймера
		}
	}

	// обновление позиции птицы в окне
	void frameBird::Update(float dt)
	{	// провер¤ю текущее состо¤ние птицы
		if (BIRD_TWO_FALLING == _birdState)
		{	// мен¤ю потложение по оси ”
			_fBirdSprite.move(0, WORLD_GRAVITY * dt);
			// мен¤ю угол
			_flightAngle += BIRD_FLIGHT_ANGLE * dt;
			// провер¤ю-мен¤ю угол наклона
			if (_flightAngle > 33.0f)
			{
				_flightAngle = 33.0f;
			}
			// ставлю угол
			_fBirdSprite.setRotation(_flightAngle);
		}
		else if (BIRD_THREE_FLYING == _birdState)
		{
			_fBirdSprite.move(0, (-0.5) * BIRD_FLY_SPEED * dt);
			// мен¤ю угол
			_flightAngle -= BIRD_FLIGHT_ANGLE * dt;
			// провер¤ю-мен¤ю угол наклона
			if (_flightAngle < -33.0f)
			{
				_flightAngle = -33.0f;
			}
			// ставлю угол
			_fBirdSprite.setRotation(_flightAngle);
		}
		// провер¤ю длительность полЄта
		if (_movementClock.getElapsedTime().asSeconds() > BIRD_FLY_DURATION)
		{	// сбрасываю врем¤ полЄта
			_movementClock.restart();
			_birdState = BIRD_TWO_FALLING; // состо¤ние - птица падает
		}
	}

	void frameBird::Tap()
	{	// обработка нажатий
		_movementClock.restart();
		_birdState = BIRD_THREE_FLYING; // в процессе полЄта
	}

	const sf::Sprite &frameBird::GetSprite() const  
	{
		return _fBirdSprite;
	}
}
