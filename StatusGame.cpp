#include "StatusGame.hpp"
#include "DefiningSplashScreen.hpp"
#include <iostream>
#include "AllCollisions.hpp" 
#include "EndGameOver.hpp"

namespace SoundSonar
{	// GameState
	StatusGame::StatusGame(GameBirdDataRef data) : _data(data)
	{	}
	// инициализирую заставку
	void StatusGame::Init()
	{	// проверяю нажатие кнопки std::cout << "Game Load" << std::endl;
		// проверка для загрузки звуков
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
		// загружаю рисунок заставки из ресурсов
		_data->assetcontrols.LoadTextureImage("Game Background",
			GAME_BACKGROUND_FILEPATH);
		// загружаю рисунки блоков сверху
		_data->assetcontrols.LoadTextureImage("Pipe Up",
			PIPE_UP_FILEPATH);
		// загружаю рисунки блоков снизу
		_data->assetcontrols.LoadTextureImage("Pipe Down",
			PIPE_DOWN_FILEPATH);
		// загружаю рисунки для земли
		_data->assetcontrols.LoadTextureImage("LandGame",
			LAND_FILEPATH);
		// загрузка рисунков птицы (кадры анимации)
		_data->assetcontrols.LoadTextureImage("Bird Frame_1", BIRD_FRAME1_FILEPATH);
		_data->assetcontrols.LoadTextureImage("Bird Frame_2", BIRD_FRAME2_FILEPATH);
		_data->assetcontrols.LoadTextureImage("Bird Frame_3", BIRD_FRAME3_FILEPATH);
		_data->assetcontrols.LoadTextureImage("Bird Frame_4", BIRD_FRAME4_FILEPATH);
		// подсчёт пройденых препятствий 
		_data->assetcontrols.LoadTextureImage("Scoring BlockPipe", BLOCK_SCORING_FILEPATH);
		// вывод счёта на окно 
		_data->assetcontrols.LoadSomeFont("Score font", SCORE_FONT_FILEPATH);
		// создаю объекты для блоков и земли
		blockPipe = new BlockPipe(_data); // препятствия
		gameLand = new GameLand(_data); // земля
		fBird = new frameBird(_data); // птичка
		glossFlashSpeed = new GlossFlashSpeed(_data); // красная вспышка - столкновение
		displayPlayerScore = new DisplayPlayerScore(_data); // счёт в игре
		// устанавливаю рисунок
		_background.setTexture(this->_data->assetcontrols.GetTexture("Game Background"));
		// переменная для подсчета очков в игре
		_score = 0;
		// обновление результата в окне
		displayPlayerScore->UpdateScore(_score);
		// установка статуса игры
		_gameState = GameBirdStates::eReady;
	}

	void StatusGame::HandleInput()
	{
		sf::Event event;

		while (_data->window.pollEvent(event))
		{
			if (sf::Event::Closed == event.type)
			{	// закрываю окно
				_data->window.close();
			}
			// появление препятствий (сперва по нажатию - проверка)	
			if (_data->input.IsSpriteClicked(_background, sf::Mouse::Left, _data->window))
			{
				// проверяю в каком статусе игра
				if (GameBirdStates::eGameOver != _gameState)
				{	// запуск игрового режима после нажатия мышки
					_gameState = GameBirdStates::ePlayGame;
					// если не геймовер
					fBird->Tap();
					// озвучиваю
					_wingWav.play();
				}
			}
		}
	}

	void StatusGame::Update(float dt)
	{
		// проверяю в каком статусе игра
		if (GameBirdStates::eGameOver != _gameState)
		{	// запуск анимации птицы
			fBird->AnimateBird(dt);
			// появление поверхности - земли
			gameLand->MoveGameLand(dt);
		}
		if (GameBirdStates::ePlayGame == _gameState)
		{	// если стоит статус игры,то:
			// появление препятствий
			blockPipe->MoveBlockPipes(dt);
			// появление препятсий по времени
			if (clock.getElapsedTime().asSeconds() > PIPE_SPAWN_FREQUENCY)
			{	// случайные позиции по У
				blockPipe->Ramdom_Y_BlockPipeOffset();
				// вывод на экран
				blockPipe->SpawnInvisiblePipesBlock();
				blockPipe->SpawnBottomPipesBlock();
				blockPipe->SpawnTopPipesBlock();
				// вывод текущего результата
				blockPipe->ScoringPlayerBlocks();
				// перезапуск текущего времени
				clock.restart();
			}
			// обновляю позицию птицы в окне
			fBird->Update(dt);
			// беру игровую поверхность земли
			std::vector<sf::Sprite> landSprites = gameLand->GetSprites();
			for (int i = 0; i < landSprites.size(); i++)
			{	// есть ли какие-либо пересечения (большая точность касания)
				if (allCollisions.CheckAllCollisions(fBird->GetSprite(), 0.995f, landSprites.at(i), 0.995f))
				{	// если происходит столкновение - GameOver
					_gameState = GameBirdStates::eGameOver;
					// перезапуск таймера
					clock.restart();
					// озвучиваю
					_hitWav.play();
				}
			}

			// тоже для блоков препятствий
			std::vector<sf::Sprite> BlockPipe = blockPipe->GetSprites();
			// если попадение в блок
			for (int i = 0; i < BlockPipe.size(); i++)
			{	// есть ли какие-либо пересечения (большая точность касания)
				if (allCollisions.CheckAllCollisions(fBird->GetSprite(), 0.7f, BlockPipe.at(i), 0.9f))
				{	// если происходит столкновение - GameOver
					_gameState = GameBirdStates::eGameOver;
					// перезапуск таймера
					clock.restart();
					// озвучиваю
					_hitWav.play();
				}
			}

			// проверяю текущий статус игры (чтобы не считать очки при геймовере)
			if (GameBirdStates::ePlayGame == _gameState)
			{	// тоже для демонстрации набранных очков
				std::vector<sf::Sprite>& scoringBlocks = blockPipe->GetScoringPlayerBlocks();
				// если блок пройдет
				for (int i = 0; i < scoringBlocks.size(); i++)
				{	// есть ли какие-либо пересечения (большая точность касания)
					if (allCollisions.CheckAllCollisions(fBird->GetSprite(), 0.7f, scoringBlocks.at(i), 0.9f))
					{	// добавление очков при прохождении каждого препятствия
						_score++;
	// убираю	std::cout << _score << std::endl; // проверка результата в консоле
						// обновление результатов на экране
						displayPlayerScore->UpdateScore(_score);
						// чищу текущее количество очков на экране, но добавляю 1
						scoringBlocks.erase(scoringBlocks.begin() + i);
						// озвучиваю
						_pointWav.play();
					}
				}
			}
		}

		// каков статус игры
		if (GameBirdStates::eGameOver == _gameState)
		{
			glossFlashSpeed->Show( dt);
			// смотрю время, сверяю
			if (clock.getElapsedTime().asSeconds() > TIME_BEFORE_GAME_OVER)
			{	// фон для геймовера, счет, кнопка
				_data->mashinegame.AddState(StateRef(new EndGameOver(_data, _score)), true);
			}
		}
	}

	void StatusGame::Draw(float dt)
	{	// чищу окно
		_data->window.clear();
		// рисую подложку (рисунок из ресурсов)
		_data->window.draw(_background);
		// рисую препятствия-блоки
		blockPipe->DrawPipesBlock();
		// рисую игровую землю
		gameLand->DrawingGameLand();
		// рисую птицу
		fBird->Draw();
		// рисую вспышку
		glossFlashSpeed->Draw();
		// рисую результат игры
		displayPlayerScore->Draw();
		// показываю на экране
		_data->window.display();
	}
}