#include "StatusGame.hpp"
#include "DefiningSplashScreen.hpp"
#include <iostream>
#include "AllCollisions.hpp" 
#include "EndGameOver.hpp"

namespace SoundSonar
{	// GameState
	StatusGame::StatusGame(GameBirdDataRef data) : _data(data)
	{	}
	// ������������� ��������
	void StatusGame::Init()
	{	// �������� ������� ������ std::cout << "Game Load" << std::endl;
		// �������� ��� �������� ������
		if (!_hitWavBuffer.loadFromFile(SOUND_HIT_FILEPATH))
		{
			std::cout << "Error Hit Sound!" << std::endl;
		}
		if (!_pointWavBuffer.loadFromFile(SOUND_POINT_FILEPATH))
		{
			std::cout << "Error Point Sound!" << std::endl;
		}
		if (!_wingWavBuffer.loadFromFile(SOUND_WING_FILEPATH))
		{
			std::cout << "Error Wing Sound!" << std::endl;
		}
		if (!_completeWavBuffer.loadFromFile(SOUND_COMLETE_FILEPATH))
		{
			std::cout << "Error Complete Sound!" << std::endl;
		}
		_hitWav.setBuffer(_hitWavBuffer);
		_pointWav.setBuffer(_pointWavBuffer);
		_wingWav.setBuffer(_wingWavBuffer);
		_completeWav.setBuffer(_completeWavBuffer);
		// �������� ������� �������� �� ��������
		_data->assetcontrols.LoadTextureImage("Game Background",
			GAME_BACKGROUND_FILEPATH);
		// �������� ������� ������ ������
		_data->assetcontrols.LoadTextureImage("Pipe Up",
			PIPE_UP_FILEPATH);
		// �������� ������� ������ �����
		_data->assetcontrols.LoadTextureImage("Pipe Down",
			PIPE_DOWN_FILEPATH);
		// �������� ������� ��� �����
		_data->assetcontrols.LoadTextureImage("LandGame",
			LAND_FILEPATH);
		// �������� �������� ����� (����� ��������)
		_data->assetcontrols.LoadTextureImage("Bird Frame_1", BIRD_FRAME1_FILEPATH);
		_data->assetcontrols.LoadTextureImage("Bird Frame_2", BIRD_FRAME2_FILEPATH);
		_data->assetcontrols.LoadTextureImage("Bird Frame_3", BIRD_FRAME3_FILEPATH);
		_data->assetcontrols.LoadTextureImage("Bird Frame_4", BIRD_FRAME4_FILEPATH);
		// ������� ��������� ����������� 
		_data->assetcontrols.LoadTextureImage("Scoring BlockPipe", BLOCK_SCORING_FILEPATH);
		// ����� ����� �� ���� 
		_data->assetcontrols.LoadSomeFont("Score font", SCORE_FONT_FILEPATH);
		// ������ ������� ��� ������ � �����
		blockPipe = new BlockPipe(_data); // �����������
		gameLand = new GameLand(_data); // �����
		fBird = new frameBird(_data); // ������
		glossFlashSpeed = new GlossFlashSpeed(_data); // ������� ������� - ������������
		displayPlayerScore = new DisplayPlayerScore(_data); // ���� � ����
		// ������������ �������
		_background.setTexture(this->_data->assetcontrols.GetTexture("Game Background"));
		// ���������� ��� �������� ����� � ����
		_score = 0;
		// ���������� ���������� � ����
		displayPlayerScore->UpdateScore(_score);
		// ��������� ������� ����
		_gameState = GameBirdStates::eReady;
	}

	void StatusGame::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{	// �������� ����
				_data->window.close();
			}
			// ��������� ����������� (������ �� ������� - ��������)	
			if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window))
			{
				// �������� � ����� ������� ����
				if (GameBirdStates::eGameOver != _gameState)
				{	// ������ �������� ������ ����� ������� �����
					_gameState = GameBirdStates::ePlayGame;
					// ���� �� ��������
					fBird->Tap();
					// ���������
					_wingWav.play();
				}
			}
		}
	}

	void StatusGame::Update(float dt)
	{
		// �������� � ����� ������� ����
		if (GameBirdStates::eGameOver != _gameState)
		{	// ������ �������� �����
			fBird->AnimateBird(dt);
			// ��������� ����������� - �����
			gameLand->MoveGameLand(dt);
		}
		if (GameBirdStates::ePlayGame == _gameState)
		{	// ���� ����� ������ ����,��:
			// ��������� �����������
			blockPipe->MoveBlockPipes(dt);
			// ��������� ��������� �� �������
			if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
			{	// ��������� ������� �� �
				blockPipe->Ramdom_Y_BlockPipeOffset();
				// ����� �� �����
				blockPipe->SpawnInvisiblePipesBlock();
				blockPipe->SpawnBottomPipesBlock();
				blockPipe->SpawnTopPipesBlock();
				// ����� �������� ����������
				blockPipe->ScoringPlayerBlocks();
				// ���������� �������� �������
				clock.restart();
			}
			// �������� ������� ����� � ����
			fBird->Update(dt);
			// ���� ������� ����������� �����
			std::vector<sf::Sprite> landSprites = gameLand->GetSprites();
			for (int i = 0; i < landSprites.size(); i++)
			{	// ���� �� �����-���� ����������� (������� �������� �������)
				if (allCollisions.CheckAllCollisions(fBird->GetSprite(), 0.995f, landSprites.at(i), 0.995f))
				{	// ���� ���������� ������������ - GameOver
					_gameState = GameBirdStates::eGameOver;
					// ���������� �������
					clock.restart();
					// ���������
					_hitWav.play();
				}
			}

			// ���� ��� ������ �����������
			std::vector<sf::Sprite> BlockPipe = blockPipe->GetSprites();
			// ���� ��������� � ����
			for (int i = 0; i < BlockPipe.size(); i++)
			{	// ���� �� �����-���� ����������� (������� �������� �������)
				if (allCollisions.CheckAllCollisions(fBird->GetSprite(), 0.7f, BlockPipe.at(i), 0.9f))
				{	// ���� ���������� ������������ - GameOver
					_gameState = GameBirdStates::eGameOver;
					// ���������� �������
					clock.restart();
					// ���������
					_hitWav.play();
				}
			}

			// �������� ������� ������ ���� (����� �� ������� ���� ��� ���������)
			if (GameBirdStates::ePlayGame == _gameState)
			{	// ���� ��� ������������ ��������� �����
				std::vector<sf::Sprite>& scoringBlocks = blockPipe->GetScoringPlayerBlocks();
				// ���� ���� �������
				for (int i = 0; i < scoringBlocks.size(); i++)
				{	// ���� �� �����-���� ����������� (������� �������� �������)
					if (allCollisions.CheckAllCollisions(fBird->GetSprite(), 0.7f, scoringBlocks.at(i), 0.9f))
					{	// ���������� ����� ��� ����������� ������� �����������
						_score++;
	// ������	std::cout << _score << std::endl; // �������� ���������� � �������
						// ���������� ����������� �� ������
						displayPlayerScore->UpdateScore(_score);
						// ���� ������� ���������� ����� �� ������, �� �������� 1
						scoringBlocks.erase(scoringBlocks.begin() + i);
						// ���������
						_pointWav.play();
					}
				}
			}
		}

		// ����� ������ ����
		if (GameBirdStates::eGameOver == _gameState)
		{
			glossFlashSpeed->Show( dt);
			// ������ �����, ������
			if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER)
			{	// ��� ��� ���������, ����, ������
				_data->mashinegame.AddState(StateRef(new EndGameOver(_data, _score)), true);
			}
		}
	}

	void StatusGame::Draw(float dt)
	{	// ���� ����
		_data->window.clear();
		// ����� �������� (������� �� ��������)
		_data->window.draw(_background);
		// ����� �����������-�����
		blockPipe->DrawPipesBlock();
		// ����� ������� �����
		gameLand->DrawingGameLand();
		// ����� �����
		fBird->Draw();
		// ����� �������
		glossFlashSpeed->Draw();
		// ����� ��������� ����
		displayPlayerScore->Draw();
		// ��������� �� ������
		_data->window.display();
	}
}