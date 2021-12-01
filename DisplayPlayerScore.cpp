#include "DisplayPlayerScore.hpp"
#include <string>
// вывод результата игры
namespace SoundSonar
{
	DisplayPlayerScore::DisplayPlayerScore(GameBirdDataRef data) : _data(data)
	{	// назначаю шрифт для результатов
		_scoreText.setFont(_data->assetcontrols.GetFont("Score font"));
		_scoreText.setString("0"); // очки в начале игры
		_scoreText.setCharacterSize(96); // размер шрифта
		_scoreText.setFillColor(sf::Color::Magenta); // цвет шрифта
		_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 0.7,
			_scoreText.getGlobalBounds().height / 2); // положение на окне
		_scoreText.setPosition(_data->window.getSize().x / 4.7, 
			_data->window.getSize().y / 15.2); // позиция относительно окна / подбором
	}

	// для вывода на экран
	void DisplayPlayerScore::Draw()
	{
		_data->window.draw(_scoreText);
	}

	// для обновления результатов (текущий результат)
	void DisplayPlayerScore::UpdateScore(int score)
	{	// перевожу результат в строку
		_scoreText.setString(std::to_string(score));
	}
}
