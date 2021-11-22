#include "DisplayPlayerScore.hpp"
#include <string>
// ����� ���������� ����
namespace SoundSonar
{
	DisplayPlayerScore::DisplayPlayerScore(GameBirdDataRef data) : _data(data)
	{	// �������� ����� ��� �����������
		_scoreText.setFont(_data->assetcontrols.GetFont("Score font"));
		_scoreText.setString("0"); // ���� � ������ ����
		_scoreText.setCharacterSize(96); // ������ ������
		_scoreText.setFillColor(sf::Color::Magenta); // ���� ������
		_scoreText.setOrigin(_scoreText.getGlobalBounds().width / 0.7,
			_scoreText.getGlobalBounds().height / 2); // ��������� �� ����
		_scoreText.setPosition(_data->window.getSize().x / 4.7, 
			_data->window.getSize().y / 15.2); // ������� ������������ ���� / ��������
	}

	// ��� ������ �� �����
	void DisplayPlayerScore::Draw()
	{
		_data->window.draw(_scoreText);
	}

	// ��� ���������� ����������� (������� ���������)
	void DisplayPlayerScore::UpdateScore(int score)
	{	// �������� ��������� � ������
		_scoreText.setString(std::to_string(score));
	}
}