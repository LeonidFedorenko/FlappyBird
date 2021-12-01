#pragma once
#include <memory>
#include <SFML/Graphics.hpp>
#include "AssetsСontrol.hpp"
#include "GameMashine.hpp"
#include "ManagerInput.hpp"

namespace SoundSonar
{	// структура для игры
	struct GameBirdData
	{
		GameMashine mashinegame; // статус игры
		sf::RenderWindow window; // окно
		AssetsControl assetcontrols; // фон, шрифт
		ManagerInput input; // ввод
	};

	typedef std::shared_ptr<GameBirdData> GameBirdDataRef;

	class Game // класс для игры
	{
	public:
		Game(int width, int height, std::string title);
	private:
		// обновления выполняются со скоростью 60 в секунду
		const float dt = 1.0f / 60.0f;
		sf::Clock _clock; // время
		// для создания и запуска игры
		GameBirdDataRef _data = std::make_shared<GameBirdData>();
		void Run(); // запуск
	};
}
