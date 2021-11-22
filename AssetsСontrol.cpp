#include <SFML/Graphics.hpp>
#include "Assets�ontrol.hpp"

namespace SoundSonar
{
	void AssetsControl::LoadTextureImage(std::string name, std::string fileName)
	{	// ��� �������� ��������
		sf::Texture texPNG;

		if (texPNG.loadFromFile(fileName))
		{	// �������� �������� �������
			this->_textures[name] = texPNG;
		}
	}

	sf::Texture &AssetsControl::GetTexture(std::string name)
	{	// ������� �������� �� ����� 
		return this->_textures.at(name);
	}

	void AssetsControl::LoadSomeFont(std::string name, std::string fileName)
	{	// ��� �������� �������� (������)
		sf::Font font;

		if (font.loadFromFile(fileName))
		{	// �������� �������� �������
			this->_fonts[name] = font;
		}
	}

	sf::Font& AssetsControl::GetFont(std::string name)
	{
		return this->_fonts.at(name);
	}
}
