#include <sstream>
#include "EndGameOver.hpp"
#include "DefiningSplashScreen.hpp"
#include "StatusGame.hpp"
#include <iostream>
// ��� ������/������ ���������� � ���� (PlayerScore.dat)
#include <fstream>

namespace SoundSonar
{	// � ����� ���� ���� �����������
	EndGameOver::EndGameOver(GameBirdDataRef data, int score) : _data(data), _score(score)
	{	}
	// ������������� ��������
	void EndGameOver::Init()
	{	// ��� ������ ����� ����������� PlayerScore.dat
		std::ifstream readFileScore;
		readFileScore.open("Resources/PlayerScore.dat");
		// �������� ������� �� ��������� ����
		if (readFileScore.is_open())
		{	// ���� ���� �� ����������
			while (!readFileScore.eof())
			{	// ������ ���������
				readFileScore >> _highScorePlay;
			}
		}
		// �������� ����
		readFileScore.close();
		// ��� ���������� �����
		std::ofstream writeFileScore("Resources/PlayerScore.dat");
		// ���� ������� ������� ����
		if (writeFileScore.is_open())
		{	// ���� ������� ��������� ������ ���������� - ������ ������ ��������
			if (_score> _highScorePlay)
			{	// ����� ��������
				_highScorePlay = _score;
			}	// ������ � ����
			writeFileScore << _highScorePlay; 
		}
		// �������� ����
		writeFileScore.close();
		// �������� ��� ��������� �� ��������
		_data->assetcontrols.LoadTextureImage("Game Over Background",
			GAME_OVER_BACKGROUND_FILEPATH);
		// �������� ��������� ��������� �� ��������
		_data->assetcontrols.LoadTextureImage("Title Game Over",
			TITLE_GAME_OVER_FILEPATH);
		// �������� ����� ��� ���������� �� ��������
		_data->assetcontrols.LoadTextureImage("Info Game Over",
			INFO_GAME_OVER_FILEPATH);
		// �������� ������
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
		// ������������ ������� ����
		_background.setTexture(this->_data->assetcontrols.GetTexture("Game Over Background"));
		// ������������ ���������
		_titleGameOver.setTexture(this->_data->assetcontrols.GetTexture("Title Game Over"));
		// ������������ ������� ��� �����������
		_bodyScoreContainer.setTexture(this->_data->assetcontrols.GetTexture("Info Game Over"));
		// ������������ ������ ��� ���� �����
		_retryPlayButton.setTexture(this->_data->assetcontrols.GetTexture("Play Button"));
		// ������� ��� ��������� ���������
		_titleGameOver.setPosition((_data->window.getSize().x / 2) -
			(_titleGameOver.getGlobalBounds().width / 2), _bodyScoreContainer.getPosition().y + 50 - 
			(_titleGameOver.getGlobalBounds().height / 12.5));
		// �������� ������� ���� ��� ����������� � ����
		_bodyScoreContainer.setPosition((_data->window.getSize().x / 2) -
			(_bodyScoreContainer.getGlobalBounds().width / 2), (_data->window.getSize().y / 2) -
			(_bodyScoreContainer.getGlobalBounds().height / 2));
		// �������� ������� ��� ����� ����������
		_retryPlayButton.setPosition((_data->window.getSize().x / 2) -
			(_retryPlayButton.getGlobalBounds().width / 2), _bodyScoreContainer.getPosition().y +
			_bodyScoreContainer.getGlobalBounds().height + (_retryPlayButton.getGlobalBounds().height * 0.2));
		// ����� ������� ��������
		_scorePlayer.setFont(_data->assetcontrols.GetFont("Score font")); // �����
		//_score.setString(std::to_string(_score)); // �������� ����� � ������
		_scorePlayer.setString(std::to_string(_score));
		_scorePlayer.setCharacterSize(54); // ������ ������
		_scorePlayer.setFillColor(sf::Color::Magenta); // ���� ������
		// ������� ��� ��������������� ��������
		_scorePlayer.setOrigin(_scorePlayer.getGlobalBounds().width / 2.5,
			_scorePlayer.getGlobalBounds().height / 2);
		// �������� ������� � ����
		_scorePlayer.setPosition(_data->window.getSize().x / 11 * 6.85,
			_data->window.getSize().y / 2.15);
		// ����� ������� ��������
		_HighScorePlayer.setFont(_data->assetcontrols.GetFont("Score font")); // �����
		_HighScorePlayer.setString(std::to_string(_highScorePlay)); // �������� ����� � ������
		_HighScorePlayer.setCharacterSize(54); // ������ ������
		_HighScorePlayer.setFillColor(sf::Color::Red); // ���� ������
		// ������� ��� ���������� ����������
		_HighScorePlayer.setOrigin(_HighScorePlayer.getGlobalBounds().width / 2.5,
			_HighScorePlayer.getGlobalBounds().height / 2);
		// �������� ������� � ����
		_HighScorePlayer.setPosition(_data->window.getSize().x / 11 * 6.85,
			_data->window.getSize().y / 1.79);
		// �������� ��������� ��������� (��� ������)
		if (_score >= SCORE_PLATINUM_MEDAL)
		{	// �������� ��������������� �������
			_medalPlayer.setTexture(_data->assetcontrols.GetTexture("MedalPlatinum"));
		}
		else if (_score >= SCORE_GOLD_MEDAL)
		{	// �������� ��������������� �������
			_medalPlayer.setTexture(_data->assetcontrols.GetTexture("MedalGold"));
		}
		else if (_score >= SCORE_SILVER_MEDAL)
		{	// �������� ��������������� �������
			_medalPlayer.setTexture(_data->assetcontrols.GetTexture("MedalSilver"));
		}
		else if (_score >= SCORE_BRONZE_MEDAL)
		{	// �������� ��������������� �������
			_medalPlayer.setTexture(_data->assetcontrols.GetTexture("MedalBronze"));
		}
		else   
		{	// �������� ��������������� �������
			_medalPlayer.setTexture(_data->assetcontrols.GetTexture("MedalNone"));
		}
		// ������������ ������� ��� ��������� ������
		_medalPlayer.setPosition(175, 465);
	}

	void EndGameOver::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{	// �������� ����
				_data->window.close();
			}
			// ���� ����� ������� ���� ���� ������ ������ ����������
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
	{	// ���� ����
		_data->window.clear();
		// ����� �������� (������� �� ��������)
		_data->window.draw(_background);
		// ��� ���������
		_data->window.draw(_titleGameOver);
		_data->window.draw(_bodyScoreContainer);
		_data->window.draw(_retryPlayButton); // ������ ����������
		// ����� �������� ��� ������ (� ������ ���������)
		_data->window.draw(_scorePlayer);
		_data->window.draw(_HighScorePlayer);
		// ��������� ������
		_data->window.draw(_medalPlayer);
		// ��������� �� ������
		_data->window.display();
	}
}