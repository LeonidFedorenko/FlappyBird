#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> // �����
#include "State.hpp"
#include "GameLoop.hpp"
#include <iostream>

namespace SoundSonar
{	// ��� ��������
	class LoadSplashHeader : public State
	{
	public:
		LoadSplashHeader(GameBirdDataRef data);

		void Init();

		void HandleInput();

		void Update(float dt);

		void Draw(float dt);

	private:
		GameBirdDataRef _data;
		// ����� ��������
		sf::Clock _clock;
		// ����	
		sf::SoundBuffer _completeWavBuffer;
		sf::Sound _completeWav;
		// ��������-��������
		sf::Sprite _background;
	};
}