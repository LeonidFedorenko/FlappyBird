#pragma once
#include <SFML/Graphics.hpp>
#include "DefiningSplashScreen.hpp"
#include "GameLoop.hpp"
#include "vector"

namespace SoundSonar
{
	class frameBird
	{
	public: // получаю птичку
		frameBird(GameBirdDataRef data);
		void Draw(); // рисую птичку
		void AnimateBird(float dt); // анимация птицы
		// добавляю действие гравитации
		void Update(float dt);
		void Tap(); // нажатие
		// дл¤ проверки столкновений
		const sf::Sprite &GetSprite() const;
	private: // из нескольких рисунков
		GameBirdDataRef _data;
		sf::Sprite _fBirdSprite;
		// текстуры анимации
		std::vector<sf::Texture> _animationFrames;
		// переменная для кадров анимации
		unsigned int _animationIterator;
		// время для анимации
		sf::Clock _clock;
		// физика зависит от времени
		sf::Clock _movementClock;
		// переменна¤ для текущего состо¤ни¤ птицы
		int _birdState;
		// дл¤ смены угла полёта птицы
		float _flightAngle;
	};
}
