#pragma once
// ����� ������ ���� ��������
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024
// ��������� 
#define WINDOW_TITLE "Game ''Flappy Bird'' / Management: left mouse button."
// ������ ������
#define IDI_ICON1 "Resources/FlappyBird.ico"
// ����� ������ ���������
#define SPLASH_STATE_SHOW_TIME 2.5
// ���� ���� ��� ��������
#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/SplashGame.png"
// ������� �������� ��� ��������� ����
// 1. ��� - ����, ������, ������, ����
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/SkySunGame.png"
// 2. ��������� ���� - ������� (RU-EN)
#define GAME_TITLE_FILEPATH "Resources/TitleGame.png"
// 3. ������ ��� ������� ����
#define PLAY_BUTTON_FILEPATH "Resources/PlayButton.png"
// ��� ��� ���� 
#define GAME_BACKGROUND_FILEPATH "Resources/SkyFonGame.png"
// ��� ��� GameOver 
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/FonGameOver.png"
// �����������
#define PIPE_UP_FILEPATH "Resources/PipeUp.png"
#define PIPE_DOWN_FILEPATH "Resources/PipeDown.png"
// ��� �������� ����� � ������� 
#define BLOCK_SCORING_FILEPATH "Resources/InvisibleBlockScoring.png"
// �������� �������� ����������
#define PIPE_MOVEMENT_SPEED 235.0f
// ������� ��������� �����������
#define PIPE_SPAWN_FREQUENCY 3.3f
// ����� � ���� (�������)
#define LAND_FILEPATH "Resources/LandGame.png"
// �������� ��� �������� ������
#define BIRD_FRAME1_FILEPATH "Resources/fbird1.png"
#define BIRD_FRAME2_FILEPATH "Resources/fbird2.png"
#define BIRD_FRAME3_FILEPATH "Resources/fbird3.png"
#define BIRD_FRAME4_FILEPATH "Resources/fbird4.png"
// ����� ��� ����������� ����
#define SCORE_FONT_FILEPATH "Resources/ScoreFont.ttf"
// ��������� ��� ���������
#define TITLE_GAME_OVER_FILEPATH "Resources/Title-Game-Over.png"
// ���� �� ������ ��� ���������
#define INFO_GAME_OVER_FILEPATH "Resources/Game-Over-Body.png"
// ����� ������
#define MEDAL_NONE_FILEPATH "Resources/MedalNone.png"
#define MEDAL_BRONZE_FILEPATH "Resources/MedalBronze.png"
#define MEDAL_SILVER_FILEPATH "Resources/MedalSilver.png"
#define MEDAL_GOLD_FILEPATH "Resources/MedalGold.png"
#define MEDAL_PLATINUM_FILEPATH "Resources/MedalPlatinum.png"
// ��� �������� ����� (����� ����� ��������)
#define BIRD_ANIMATION_DURATION 0.3f
// ����� � ����
#define SOUND_HIT_FILEPATH "Resources/Hit.wav"
#define SOUND_POINT_FILEPATH "Resources/Point.wav" 
#define SOUND_WING_FILEPATH "Resources/Wing.wav"
#define SOUND_COMLETE_FILEPATH "Resources/Complete.wav"
// ��������� ����� �����
#define BIRD_ONE_STILL 1 // �������
#define BIRD_TWO_FALLING 2 // �������
#define BIRD_THREE_FLYING 3 // � �������� �����
// ���� ����������
#define WORLD_GRAVITY 70.0f
// �������� ����� �����
#define BIRD_FLY_SPEED 130.0f
// ������������ ����� �����
#define BIRD_FLY_DURATION 0.45f
// ��� ����� ����������� ����� ����� (����-���� ����� ����)
#define BIRD_FLIGHT_ANGLE 60.0f
// ������ ������������ ��� �������� ����
enum GameBirdStates
{
	eReady,
	ePlayGame,
	eGameOver
};
// ������� ��� ������������ � ������������ (�������)
#define GLOSS_FLASH_SPEED 1777.7f
// ����� ��� ���������
#define TIME_BEFORE_GAME_OVER 0.7f
// ���������� ����� ��� ��������� ������
#define SCORE_NONE_MEDAL 0
#define SCORE_BRONZE_MEDAL 20
#define SCORE_SILVER_MEDAL 50
#define SCORE_GOLD_MEDAL 80
#define SCORE_PLATINUM_MEDAL 110