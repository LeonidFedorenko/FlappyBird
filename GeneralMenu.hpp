#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> // звук
#include "State.hpp"
#include "GameLoop.hpp"
// игровое меню
namespace SoundSonar
{
	class GeneralMenu : public State
	{
	public:
		GeneralMenu(GameBirdDataRef data);

		void Init();

		void HandleInput();

		void Update(float dt);

		void Draw(float dt);

	private:
		GameBirdDataRef _data;
// звук для меню
		sf::SoundBuffer _completeWavBuffer;
		sf::Sound _completeWav;
// фон, заголовок, кнопка
		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _playButton;
		
	};
}