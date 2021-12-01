#pragma once

#include <SFML/Graphics.hpp> // графика
#include "State.hpp" // состояние игры
#include <SFML/Audio.hpp> // звуки
#include "GameLoop.hpp" // игра
#include "BlockPipe.hpp" // птица
#include "LandGame.hpp" // земля
#include "AnimationBird.hpp" // анимация птицы
#include "AllCollisions.hpp" // столкновения
#include "GlossFlashSpeed.hpp" // вспышка
#include "DisplayPlayerScore.hpp" // вывод результата

namespace SoundSonar
{	// игровой статус
	class StatusGame : public State
	{
	public:
		StatusGame(GameBirdDataRef data);

		void Init();

		void HandleInput();

		void Update(float dt);

		void Draw(float dt);

	private:
		GameBirdDataRef _data;
		// фон окна
		sf::Sprite _background;
		// препятствия
		BlockPipe *blockPipe;
		// игровая поверхность - земля
		GameLand *gameLand;
		// птичка
		frameBird *fBird;
		// красная вспышка при столкновении
		GlossFlashSpeed* glossFlashSpeed;
		// текущий результат на окне
		DisplayPlayerScore* displayPlayerScore;
		// столкновения
		AllCollisions allCollisions;
		// для времени появления нового препятствия
		sf::Clock clock;
		// звуки в игре
		sf::SoundBuffer _hitWavBuffer;
		sf::SoundBuffer _completeWavBuffer;
		sf::SoundBuffer _pointWavBuffer;
		sf::SoundBuffer _wingWavBuffer;
		sf::Sound _hitWav;
		sf::Sound _completeWav;
		sf::Sound _pointWav;
		sf::Sound _wingWav;
		// переменная статуса
		int _gameState;
		// переменная для подсчета результата
		int _score;
	};
}
