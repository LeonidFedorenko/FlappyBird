#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp> // ����
#include "State.hpp"
#include "GameLoop.hpp"
// ������� ����
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
// ���� ��� ����
		sf::SoundBuffer _completeWavBuffer;
		sf::Sound _completeWav;
// ���, ���������, ������
		sf::Sprite _background;
		sf::Sprite _title;
		sf::Sprite _playButton;
		
	};
}