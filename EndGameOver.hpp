#pragma once
#include <SFML/Graphics.hpp>
#include "State.hpp"
#include "GameLoop.hpp"

namespace SoundSonar
{
	class EndGameOver : public State
	{	// завершение игры (gameover)
	public:
		EndGameOver(GameBirdDataRef data, int score);

		void Init();

		void HandleInput();

		void Update(float dt);

		void Draw(float dt);

	private:
		GameBirdDataRef _data;
		// фон для геймовера
		sf::Sprite _background;
		sf::Sprite _titleGameOver; // заголовок
		sf::Sprite _bodyScoreContainer; // результаты
		sf::Sprite _retryPlayButton; // кнопка "Играть"
		sf::Sprite _medalPlayer; // медаль за результат
		// для подсчёта очков и результатов (вывод на экран)
		sf::Text _scorePlayer; // текущий игрок     
		sf::Text _HighScorePlayer; // лучший результат  
		// для подсчёта очков и результатов (переменные)
		int _score; // очки текущего игрок     
		int _highScorePlay; // очки - лучший результат  
	};
}
