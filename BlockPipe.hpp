#pragma once
#include <SFML/Graphics.hpp>
#include "GameLoop.hpp"
#include "DefiningSplashScreen.hpp"
#include "GameMashine.hpp"
#include "vector"

namespace SoundSonar
{	// класс для препятствий
	class BlockPipe
	{
	public:
		BlockPipe(GameBirdDataRef data);
		// для появлние на экране препятсвий
		void SpawnBottomPipesBlock();
		void SpawnTopPipesBlock();
		void SpawnInvisiblePipesBlock();
		// чтобы показывать результат прохождения препятствий
		void ScoringPlayerBlocks();
		// для премещения препятсвий в окне
		void MoveBlockPipes(float dt);
		// прорисовка блоков
		void DrawPipesBlock();
		// метод для случайной высоты блоков по Y
		void Ramdom_Y_BlockPipeOffset();
		// для столкновений с блоками
		const std::vector<sf::Sprite> &GetSprites() const;
		// метод для подсчёта пройденых блоков
		std::vector<sf::Sprite> &GetScoringPlayerBlocks();
	private:
		GameBirdDataRef _data;
		// проверка - столкновения
		std::vector<sf::Sprite> blockPipeSprites;
		// проверка - прохождения очередного блока
		std::vector<sf::Sprite> scoringBlocks;
		int _landHeightBlockPipe; // 
		int _blockPipeSpawn_Y_Offset; //
	};
}