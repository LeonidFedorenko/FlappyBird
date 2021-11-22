#pragma once
#include <SFML/Graphics.hpp>
#include "DefiningSplashScreen.hpp"
#include "GameLoop.hpp"
#include "vector"

namespace SoundSonar
{
	class frameBird
	{
	public: // ������� ������
		frameBird(GameBirdDataRef data);
		void Draw(); // ����� ������
		void AnimateBird(float dt); // �������� �����
		// �������� �������� ����������
		void Update(float dt);
		void Tap(); // �������
		// ��� �������� ������������
		const sf::Sprite &GetSprite() const;
	private: // �� ���������� ��������
		GameBirdDataRef _data;
		sf::Sprite _fBirdSprite;
		// �������� ��������
		std::vector<sf::Texture> _animationFrames;
		// ���������� ��� ������ ��������
		unsigned int _animationIterator;
		// ����� ��� ��������
		sf::Clock _clock;
		// ������ ������� �� �������
		sf::Clock _movementClock;
		// ���������� ��� �������� ��������� �����
		int _birdState;
		// ��� ����� ���� ����� �����
		float _flightAngle;
	};
}