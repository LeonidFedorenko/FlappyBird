#pragma once
#include <SFML/Graphics.hpp>
#include "GameLoop.hpp"
#include "AllCollisions.hpp"
#include "DefiningSplashScreen.hpp"
// обработка столкновений
namespace SoundSonar
{
	class GlossFlashSpeed // класс для вспышки при столкновении
	{
	public:
		// конструктор
		GlossFlashSpeed( GameBirdDataRef data);
		// показываю
		void Show(float dt);
		void Draw(); // рисую

	private:
		GameBirdDataRef _data;
		sf::RectangleShape _shape;
		// переменная для возможности вспышки
		bool _glossFlashON;
	};
}
