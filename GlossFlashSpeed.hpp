#pragma once
#include <SFML/Graphics.hpp>
#include "GameLoop.hpp"
#include "AllCollisions.hpp"
#include "DefiningSplashScreen.hpp"
// ��������� ������������
namespace SoundSonar
{
	class GlossFlashSpeed // ����� ��� ������� ��� ������������
	{
	public:
		// �����������
		GlossFlashSpeed( GameBirdDataRef data);
		// ���������
		void Show(float dt);
		void Draw(); // �����

	private:
		GameBirdDataRef _data;
		sf::RectangleShape _shape;
		// ���������� ��� ����������� �������
		bool _glossFlashON;
	};
}