#pragma once
#include <SFML/Graphics.hpp>
#include "DefiningSplashScreen.hpp"
#include "GameLoop.hpp"

// вывод результата игры
namespace SoundSonar
{
	class DisplayPlayerScore
	{
	public:
		DisplayPlayerScore(GameBirdDataRef data);
		// для вывода на экран
		void Draw();
		// для обновления результатов (текущий результат)
		void UpdateScore(int score);

	private:
		GameBirdDataRef _data;
		sf::Text _scoreText; // для результата
	};
}
