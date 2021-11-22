#include "AnimationBird.hpp"

namespace SoundSonar
{
	frameBird::frameBird(GameBirdDataRef data) : _data(data)
	{	// �������� �����
		_animationIterator = 0;
		// 4 ����� �������� �����
		_animationFrames.push_back(_data->assetcontrols.GetTexture("Bird Frame_1"));
		_animationFrames.push_back(_data->assetcontrols.GetTexture("Bird Frame_2"));
		_animationFrames.push_back(_data->assetcontrols.GetTexture("Bird Frame_3"));
		_animationFrames.push_back(_data->assetcontrols.GetTexture("Bird Frame_4"));
		// ��������� � �������� ��� ��������� ��������
		_fBirdSprite.setTexture(_animationFrames.at(_animationIterator));
		// ��� ��������� ������� ����� (� �����)
		_fBirdSprite.setPosition(
			(_data->window.getSize().x / 4) - (_fBirdSprite.getGlobalBounds().width / 2),
			(_data->window.getSize().y / 2) - (_fBirdSprite.getGlobalBounds().height / 2));
		_birdState = BIRD_ONE_STILL;
		// ��� ����� ����-����������� �����
		sf::Vector2f origin = sf::Vector2f(_fBirdSprite.getGlobalBounds().width / 2,
			_fBirdSprite.getGlobalBounds().height / 2); // �����
		_fBirdSprite.setOrigin(origin); // ������ ����
		_flightAngle = 0;
	}

	void frameBird::Draw()
	{	// ���������� �����
		_data->window.draw(_fBirdSprite);
	}

	// �������� ������ ��� �����
	void frameBird::AnimateBird(float dt)
	{	// �������� ����� �� ������ ���� ��� �����
		if (_clock.getElapsedTime().asSeconds() > BIRD_ANIMATION_DURATION / _animationFrames.size())
		{	// ����� ����� �������� � ����� DefiningSplashScreen.hpp
			if (_animationIterator < _animationFrames.size() - 1)
			{
				_animationIterator++;
			}
			else
			{
				_animationIterator = 0;
			}
			// ����� �������-�������� �����
			_fBirdSprite.setTexture(_animationFrames.at(_animationIterator));
			_clock.restart(); // ���������� �������
		}
	}

	// ���������� ������� ����� � ����
	void frameBird::Update(float dt)
	{	// �������� ������� ��������� �����
		if (BIRD_TWO_FALLING == _birdState)
		{	// ����� ���������� �� ��� �
			_fBirdSprite.move(0, WORLD_GRAVITY * dt);
			// ����� ����
			_flightAngle += BIRD_FLIGHT_ANGLE * dt;
			// ��������-����� ���� �������
			if (_flightAngle > 33.0f)
			{
				_flightAngle = 33.0f;
			}
			// ������ ����
			_fBirdSprite.setRotation(_flightAngle);
		}
		else if (BIRD_THREE_FLYING == _birdState)
		{
			_fBirdSprite.move(0, (-0.5) * BIRD_FLY_SPEED * dt);
			// ����� ����
			_flightAngle -= BIRD_FLIGHT_ANGLE * dt;
			// ��������-����� ���� �������
			if (_flightAngle < -33.0f)
			{
				_flightAngle = -33.0f;
			}
			// ������ ����
			_fBirdSprite.setRotation(_flightAngle);
		}
		// �������� ������������ �����
		if (_movementClock.getElapsedTime().asSeconds() > BIRD_FLY_DURATION)
		{	// ��������� ����� �����
			_movementClock.restart();
			_birdState = BIRD_TWO_FALLING; // ��������� - ����� ������
		}
	}

	void frameBird::Tap()
	{	// ��������� �������
		_movementClock.restart();
		_birdState = BIRD_THREE_FLYING; // � �������� �����
	}

	const sf::Sprite &frameBird::GetSprite() const  
	{
		return _fBirdSprite;
	}
}