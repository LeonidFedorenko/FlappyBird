#pragma once
#include <SFML/Graphics.hpp>
#include <vector>
#include "GameLoop.hpp" // Game.hpp

namespace SoundSonar
{	// земля в игре
	class GameLand
	{ // публичный метод
	public:
		GameLand(GameBirdDataRef data);
		// движение земли в игре
		void MoveGameLand(float dt);
		// прорисовка земли в игре
		void DrawingGameLand();
		// для столкновений
		const std::vector<sf::Sprite> &GetSprites() const;

	private:
		GameBirdDataRef _data;
		std::vector<sf::Sprite>_gameLandSprites;
	};
}