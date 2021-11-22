#include <SFML/Graphics.hpp>
#include "AssetsСontrol.hpp"

namespace SoundSonar
{
	void AssetsControl::LoadTextureImage(std::string name, std::string fileName)
	{	// для загрузки текстуры
		sf::Texture texPNG;

		if (texPNG.loadFromFile(fileName))
		{	// проверка загрузки ресурса
			this->_textures[name] = texPNG;
		}
	}

	sf::Texture &AssetsControl::GetTexture(std::string name)
	{	// получаю текстуру по имени 
		return this->_textures.at(name);
	}

	void AssetsControl::LoadSomeFont(std::string name, std::string fileName)
	{	// для загрузки текстуры (шрифта)
		sf::Font font;

		if (font.loadFromFile(fileName))
		{	// проверка загрузки ресурса
			this->_fonts[name] = font;
		}
	}

	sf::Font& AssetsControl::GetFont(std::string name)
	{
		return this->_fonts.at(name);
	}
}
