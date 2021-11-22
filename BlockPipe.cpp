#include "BlockPipe.hpp"

namespace SoundSonar
{
	BlockPipe::BlockPipe(GameBirdDataRef data) : _data(data)
	{	// ��� ��������� ������ ������ (�����������)
		_landHeightBlockPipe = _data->assetcontrols.GetTexture("LandGame").getSize().y;
		_blockPipeSpawn_Y_Offset = -250; 
	}

	// ��� �������� �� ������ ����������
	void BlockPipe::SpawnBottomPipesBlock()
	{	// ������������� ���� (�������� �� ��������)
		sf::Sprite sprite(_data->assetcontrols.GetTexture("Pipe Up"));
		// ������ ������� ��������� (�� ����) � ������� blockPipeSpawn_Y_Offset
		sprite.setPosition(_data->window.getSize().x, 
			_data->window.getSize().y - sprite.getGlobalBounds().height + _blockPipeSpawn_Y_Offset);
		blockPipeSprites.push_back(sprite);
	}

	void BlockPipe::SpawnTopPipesBlock()
	{	// ������������� ���� (�������� �� ��������)
		sf::Sprite sprite(_data->assetcontrols.GetTexture("Pipe Down"));
		// ������ ������� ��������� (�� ����) � ������� blockPipeSpawn_Y_Offset
		sprite.setPosition(_data->window.getSize().x, _blockPipeSpawn_Y_Offset - 420);
		blockPipeSprites.push_back(sprite);
	}

	void BlockPipe::SpawnInvisiblePipesBlock()
	{	// ������������� ���� (�������� �� ��������)
		sf::Sprite sprite(_data->assetcontrols.GetTexture("Pipe Up"));
		// ������ ������� ��������� (�� ����)
		sprite.setPosition(_data->window.getSize().x,
			_data->window.getSize().y - (sprite.getGlobalBounds().height));
		sprite.setColor(sf::Color(0, 0, 0, 0));
		blockPipeSprites.push_back(sprite);
	}

	// ������� ��������� �����������
	void BlockPipe::ScoringPlayerBlocks()
	{	// ������������� ���� ��������
		sf::Sprite sprite(_data->assetcontrols.GetTexture("Scoring BlockPipe"));
		// ������ ������� ��������� (�� ����)
		sprite.setPosition(_data->window.getSize().x, 0);
		// �����������
		scoringBlocks.push_back(sprite);
	}

	// ��� ���������� ���������� � ����
	void BlockPipe::MoveBlockPipes(float dt)
	{
		for (unsigned short int i = 0; i < blockPipeSprites.size(); i++)
		{	// ���������� �����������
			// ������ ������� ��� ��������� ������ ����������
			if (blockPipeSprites.at(i).getPosition().x < 0 - blockPipeSprites.at(i).getGlobalBounds().width)
			{ 
				blockPipeSprites.erase(blockPipeSprites.begin() + i);
			}
			else
			{
				float movement = PIPE_MOVEMENT_SPEED * dt;
				blockPipeSprites.at(i).move(-movement, 0);
			}
		}
		
		for (unsigned short int i = 0; i < scoringBlocks.size(); i++)
		{	// ���������� �����������
			// ������ ������� ��� ��������� ������ ����������
			if (scoringBlocks.at(i).getPosition().x < 0 - scoringBlocks.at(i).getGlobalBounds().width)
			{ 
				scoringBlocks.erase(scoringBlocks.begin() + i);
			}
			else
			{
				float movement = PIPE_MOVEMENT_SPEED * dt;
				scoringBlocks.at(i).move(-movement, 0);
			}
		}
	}

	void BlockPipe::DrawPipesBlock()
	{
		for (unsigned short int i = 0; i < blockPipeSprites.size(); i++)
		{	// ����� �����������
			_data->window.draw(blockPipeSprites.at(i));
		}
	}

	void BlockPipe::Ramdom_Y_BlockPipeOffset()
	{	// ��������� ��������� ������ � ���� �� �
		_blockPipeSpawn_Y_Offset = -120 + rand() % (_landHeightBlockPipe);
	}

	const std::vector<sf::Sprite> &BlockPipe::GetSprites() const
	{	// ����� ���� �����������
		return blockPipeSprites;
	}

	std::vector<sf::Sprite>& BlockPipe::GetScoringPlayerBlocks() 
	{	// ������� ��� ����������� ����� �����������
		return scoringBlocks;
	}
}