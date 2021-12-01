#include "BlockPipe.hpp"

namespace SoundSonar
{
	BlockPipe::BlockPipe(GameBirdDataRef data) : _data(data)
	{	// для случайной высоты блоков (препятствий)
		_landHeightBlockPipe = _data->assetcontrols.GetTexture("LandGame").getSize().y;
		_blockPipeSpawn_Y_Offset = -250; 
	}

	// для появлние на экране препятсвий
	void BlockPipe::SpawnBottomPipesBlock()
	{	// инициализирую блок (загружаю из ресурсов)
		sf::Sprite sprite(_data->assetcontrols.GetTexture("Pipe Up"));
		// ставлю позицию появления (от окна) и отнимаю blockPipeSpawn_Y_Offset
		sprite.setPosition(_data->window.getSize().x, 
			_data->window.getSize().y - sprite.getGlobalBounds().height + _blockPipeSpawn_Y_Offset);
		blockPipeSprites.push_back(sprite);
	}

	void BlockPipe::SpawnTopPipesBlock()
	{	// инициализирую блок (загружаю из ресурсов)
		sf::Sprite sprite(_data->assetcontrols.GetTexture("Pipe Down"));
		// ставлю позицию появления (от окна) и отнимаю blockPipeSpawn_Y_Offset
		sprite.setPosition(_data->window.getSize().x, _blockPipeSpawn_Y_Offset - 420);
		blockPipeSprites.push_back(sprite);
	}

	void BlockPipe::SpawnInvisiblePipesBlock()
	{	// инициализирую блок (загружаю из ресурсов)
		sf::Sprite sprite(_data->assetcontrols.GetTexture("Pipe Up"));
		// ставлю позицию появления (от окна)
		sprite.setPosition(_data->window.getSize().x,
			_data->window.getSize().y - (sprite.getGlobalBounds().height));
		sprite.setColor(sf::Color(0, 0, 0, 0));
		blockPipeSprites.push_back(sprite);
	}

	// подсчёт пройденых препятствий
	void BlockPipe::ScoringPlayerBlocks()
	{	// инициализирую блок подсчёта
		sf::Sprite sprite(_data->assetcontrols.GetTexture("Scoring BlockPipe"));
		// ставлю позицию появления (от окна)
		sprite.setPosition(_data->window.getSize().x, 0);
		// подсчитываю
		scoringBlocks.push_back(sprite);
	}

	// для премещения препятсвий в окне
	void BlockPipe::MoveBlockPipes(float dt)
	{
		for (unsigned short int i = 0; i < blockPipeSprites.size(); i++)
		{	// передвигаю препятствия
			// создаю условие для появление блоков препятсвий
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
		{	// передвигаю препятствия
			// создаю условие для появление блоков препятсвий
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
		{	// рисую препятствия
			_data->window.draw(blockPipeSprites.at(i));
		}
	}

	void BlockPipe::Ramdom_Y_BlockPipeOffset()
	{	// случайное положение блоков в окне по У
		_blockPipeSpawn_Y_Offset = -120 + rand() % (_landHeightBlockPipe);
	}

	const std::vector<sf::Sprite> &BlockPipe::GetSprites() const
	{	// новый блок препятствие
		return blockPipeSprites;
	}

	std::vector<sf::Sprite>& BlockPipe::GetScoringPlayerBlocks() 
	{	// подсчёт при прохождении блока препятствия
		return scoringBlocks;
	}
}
