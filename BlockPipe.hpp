#pragma once
#include <SFML/Graphics.hpp>
#include "GameLoop.hpp"
#include "DefiningSplashScreen.hpp"
#include "GameMashine.hpp"
#include "vector"

namespace SoundSonar
{	// ����� ��� �����������
	class BlockPipe
	{
	public:
		BlockPipe(GameBirdDataRef data);
		// ��� �������� �� ������ ����������
		void SpawnBottomPipesBlock();
		void SpawnTopPipesBlock();
		void SpawnInvisiblePipesBlock();
		// ����� ���������� ��������� ����������� �����������
		void ScoringPlayerBlocks();
		// ��� ���������� ���������� � ����
		void MoveBlockPipes(float dt);
		// ���������� ������
		void DrawPipesBlock();
		// ����� ��� ��������� ������ ������ �� Y
		void Ramdom_Y_BlockPipeOffset();
		// ��� ������������ � �������
		const std::vector<sf::Sprite> &GetSprites() const;
		// ����� ��� �������� ��������� ������
		std::vector<sf::Sprite> &GetScoringPlayerBlocks();
	private:
		GameBirdDataRef _data;
		// �������� - ������������
		std::vector<sf::Sprite> blockPipeSprites;
		// �������� - ����������� ���������� �����
		std::vector<sf::Sprite> scoringBlocks;
		int _landHeightBlockPipe; // 
		int _blockPipeSpawn_Y_Offset; //
	};
}