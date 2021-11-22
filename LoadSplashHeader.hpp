#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> // звуки
#include "State.hpp"
#include "GameLoop.hpp"
#include <iostream>

namespace SoundSonar
{	// для заставки
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
		// время заставки
		sf::Clock _clock;
		// звук	
		sf::SoundBuffer _completeWavBuffer;
		sf::Sound _completeWav;
		// заставка-картинка
		sf::Sprite _background;
	};
}