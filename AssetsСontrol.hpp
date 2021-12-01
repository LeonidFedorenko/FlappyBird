#pragma once
#include <map>
#include <SFML/Graphics.hpp>

// для загрузки фона и шрифта
namespace SoundSonar
{
	class AssetsControl
	{
	public:
		AssetsControl() {} // конструктор
		~AssetsControl() {} // деструктор
		// метод для загрузки рисунка (имя: ресурса-файла)
		void LoadTextureImage(std::string namePNG, std::string fileName);
		// получаю имя файла для текстуры
		sf::Texture &GetTexture(std::string namePNG);
		// метод для загрузки шрифта (имя: ресурса-файла)
		void LoadSomeFont(std::string name, std::string fileName);
		// получаю имя шрифта
		sf::Font &GetFont(std::string name);

	private:	// для интерфейса
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;

	};
}
