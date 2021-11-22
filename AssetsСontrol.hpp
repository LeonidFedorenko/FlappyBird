#pragma once
#include <map>
#include <SFML/Graphics.hpp>

// ��� �������� ���� � ������
namespace SoundSonar
{
	class AssetsControl
	{
	public:
		AssetsControl() {} // �����������
		~AssetsControl() {} // ����������
		// ����� ��� �������� ������� (���: �������-�����)
		void LoadTextureImage(std::string namePNG, std::string fileName);
		// ������� ��� ����� ��� ��������
		sf::Texture &GetTexture(std::string namePNG);
		// ����� ��� �������� ������ (���: �������-�����)
		void LoadSomeFont(std::string name, std::string fileName);
		// ������� ��� ������
		sf::Font &GetFont(std::string name);

	private:	// ��� ����������
		std::map<std::string, sf::Texture> _textures;
		std::map<std::string, sf::Font> _fonts;

	};
}
