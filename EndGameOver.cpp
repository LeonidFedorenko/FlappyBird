#include <sstream>
#include "EndGameOver.hpp"
#include "DefiningSplashScreen.hpp"
#include "StatusGame.hpp"
#include <iostream>
// для чтения/записи результата в файл (PlayerScore.dat)
#include <fstream>

namespace SoundSonar
{	// в конце игры учёт результатов
	EndGameOver::EndGameOver(GameBirdDataRef data, int score) : _data(data), _score(score)
	{	}
	// инициализирую заставку
	void EndGameOver::Init()
	{	// для чтение файла результатов PlayerScore.dat
		std::ifstream readFileScore;
		readFileScore.open("Resources/PlayerScore.dat");
		// проверяю удалось ли прочитать файл
		if (readFileScore.is_open())
		{	// пока файл не закончился
			while (!readFileScore.eof())
			{	// лучший результат
				readFileScore >> _highScorePlay;
			}
		}
		// закрываю файл
		readFileScore.close();
		// для перезаписи файла
		std::ofstream writeFileScore("Resources/PlayerScore.dat");
		// если удалось открыть файл
		if (writeFileScore.is_open())
		{	// если текущий результат больше имеющегося - запись нового значения
			if (_score> _highScorePlay)
			{	// меняю значение
				_highScorePlay = _score;
			}	// запись в файл
			writeFileScore << _highScorePlay; 
		}
		// закрываю файл
		writeFileScore.close();
		// загружаю фон геймовера из ресурсов
		_data->assetcontrols.LoadTextureImage("Game Over Background",
			GAME_OVER_BACKGROUND_FILEPATH);
		// загружаю заголовок геймовера из ресурсов
		_data->assetcontrols.LoadTextureImage("Title Game Over",
			TITLE_GAME_OVER_FILEPATH);
		// загружаю табло для информации из ресурсов
		_data->assetcontrols.LoadTextureImage("Info Game Over",
			INFO_GAME_OVER_FILEPATH);
		// загружаю медали
		_data->assetcontrols.LoadTextureImage("MedalNone",
			MEDAL_NONE_FILEPATH);
		_data->assetcontrols.LoadTextureImage("MedalBronze",
			MEDAL_BRONZE_FILEPATH);
		_data->assetcontrols.LoadTextureImage("MedalSilver",
			MEDAL_SILVER_FILEPATH);
		_data->assetcontrols.LoadTextureImage("MedalGold",
			MEDAL_GOLD_FILEPATH);
		_data->assetcontrols.LoadTextureImage("MedalPlatinum",
			MEDAL_PLATINUM_FILEPATH);
		// устанавливаю рисунок фона
		_background.setTexture(this->_data->assetcontrols.GetTexture("Game Over Background"));
		// устанавливаю заголовок
		_titleGameOver.setTexture(this->_data->assetcontrols.GetTexture("Title Game Over"));
		// устанавливаю рисунок для результатов
		_bodyScoreContainer.setTexture(this->_data->assetcontrols.GetTexture("Info Game Over"));
		// устанавливаю кнопку для игры вновь
		_retryPlayButton.setTexture(this->_data->assetcontrols.GetTexture("Play Button"));
		// позиция для заголовка геймовера
		_titleGameOver.setPosition((_data->window.getSize().x / 2) -
			(_titleGameOver.getGlobalBounds().width / 2), _bodyScoreContainer.getPosition().y + 50 - 
			(_titleGameOver.getGlobalBounds().height / 12.5));
		// указываю позицию фона для результатов в окне
		_bodyScoreContainer.setPosition((_data->window.getSize().x / 2) -
			(_bodyScoreContainer.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) -
			(_bodyScoreContainer.getGlobalBounds().height / 2));
		// указываю позицию для кноки переиграть
		_retryPlayButton.setPosition((_data->window.getSize().x / 2) -
			(_retryPlayButton.getGlobalBounds().width / 2), _bodyScoreContainer.getPosition().y +
			_bodyScoreContainer.getGlobalBounds().height + (_retryPlayButton.getGlobalBounds().height * 0.2));
		// вывод личного результа
		_scorePlayer.setFont(_data->assetcontrols.GetFont("Score font")); // шрифт
		//_score.setString(std::to_string(_score)); // перевожу число в строку
		_scorePlayer.setString(std::to_string(_score));
		_scorePlayer.setCharacterSize(54); // размер шрифта
		_scorePlayer.setFillColor(sf::Color::Magenta); // цвет шрифта
		// позиция для результирующего значения
		_scorePlayer.setOrigin(_scorePlayer.getGlobalBounds().width / 2.5,
			_scorePlayer.getGlobalBounds().height / 2);
		// указываю позицию в окне
		_scorePlayer.setPosition(_data->window.getSize().x / 11 * 6.85,
			_data->window.getSize().y / 2.15);
		// вывод лучшего результа
		_HighScorePlayer.setFont(_data->assetcontrols.GetFont("Score font")); // шрифт
		_HighScorePlayer.setString(std::to_string(_highScorePlay)); // перевожу число в строку
		_HighScorePlayer.setCharacterSize(54); // размер шрифта
		_HighScorePlayer.setFillColor(sf::Color::Red); // цвет шрифта
		// позиция для наилучшего результата
		_HighScorePlayer.setOrigin(_HighScorePlayer.getGlobalBounds().width / 2.5,
			_HighScorePlayer.getGlobalBounds().height / 2);
		// указываю позицию в окне
		_HighScorePlayer.setPosition(_data->window.getSize().x / 11 * 6.85,
			_data->window.getSize().y / 1.79);
		// проверяю набранный результат (для медали)
		if (_score >= SCORE_PLATINUM_MEDAL)
		{	// загружаю соответствующий рисунок
			_medalPlayer.setTexture(_data->assetcontrols.GetTexture("MedalPlatinum"));
		}
		else if (_score >= SCORE_GOLD_MEDAL)
		{	// загружаю соответствующий рисунок
			_medalPlayer.setTexture(_data->assetcontrols.GetTexture("MedalGold"));
		}
		else if (_score >= SCORE_SILVER_MEDAL)
		{	// загружаю соответствующий рисунок
			_medalPlayer.setTexture(_data->assetcontrols.GetTexture("MedalSilver"));
		}
		else if (_score >= SCORE_BRONZE_MEDAL)
		{	// загружаю соответствующий рисунок
			_medalPlayer.setTexture(_data->assetcontrols.GetTexture("MedalBronze"));
		}
		else   
		{	// загружаю соответствующий рисунок
			_medalPlayer.setTexture(_data->assetcontrols.GetTexture("MedalNone"));
		}
		// устанавливаю позицию для появления медали
		_medalPlayer.setPosition(175, 465);
	}

	void EndGameOver::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{	// закрываю окно
				_data->window.close();
			}
			// если левой кнопкой мыши была нажата кнопка переиграть
			if (_data->input.IsSpriteClicked(_retryPlayButton, sf::Mouse::Left, _data->window))
			{
				_data->mashinegame.AddState(StateRef(new StatusGame(_data)), true);
			}
		}
	}

	void EndGameOver::Update(float dt)
	{

	}

	void EndGameOver::Draw(float dt)
	{	// чищу окно
		_data->window.clear();
		// рисую подложку (рисунок из ресурсов)
		_data->window.draw(_background);
		// при геймовере
		_data->window.draw(_titleGameOver);
		_data->window.draw(_bodyScoreContainer);
		_data->window.draw(_retryPlayButton); // кнопка переиграть
		// вывод значений для игрока (и лучший результат)
		_data->window.draw(_scorePlayer);
		_data->window.draw(_HighScorePlayer);
		// появление медали
		_data->window.draw(_medalPlayer);
		// показываю на экране
		_data->window.display();
	}
}