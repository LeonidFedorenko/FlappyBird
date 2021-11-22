#pragma once
// задаю размер окна заставки
#define SCREEN_WIDTH 768
#define SCREEN_HEIGHT 1024
// заголовок 
#define WINDOW_TITLE "Game ''Flappy Bird'' / Management: left mouse button."
// ставлю иконку
#define IDI_ICON1 "Resources/FlappyBird.ico"
// время показа заствавки
#define SPLASH_STATE_SHOW_TIME 2.5
// файл фона для заставки
#define SPLASH_SCENE_BACKGROUND_FILEPATH "Resources/SplashGame.png"
// зарузка ресурсов для основного меню
// 1. фон - небо, солнце, облака, поле
#define MAIN_MENU_BACKGROUND_FILEPATH "Resources/SkySunGame.png"
// 2. заголовок меню - надпись (RU-EN)
#define GAME_TITLE_FILEPATH "Resources/TitleGame.png"
// 3. кнопка для запуска игры
#define PLAY_BUTTON_FILEPATH "Resources/PlayButton.png"
// фон для игры 
#define GAME_BACKGROUND_FILEPATH "Resources/SkyFonGame.png"
// фон для GameOver 
#define GAME_OVER_BACKGROUND_FILEPATH "Resources/FonGameOver.png"
// препятствия
#define PIPE_UP_FILEPATH "Resources/PipeUp.png"
#define PIPE_DOWN_FILEPATH "Resources/PipeDown.png"
// для подсчета очков в консоле 
#define BLOCK_SCORING_FILEPATH "Resources/InvisibleBlockScoring.png"
// скорость движения препятсвий
#define PIPE_MOVEMENT_SPEED 235.0f
// частота появления препятствий
#define PIPE_SPAWN_FREQUENCY 3.3f
// земля в игре (рисунок)
#define LAND_FILEPATH "Resources/LandGame.png"
// картинки для анимации птички
#define BIRD_FRAME1_FILEPATH "Resources/fbird1.png"
#define BIRD_FRAME2_FILEPATH "Resources/fbird2.png"
#define BIRD_FRAME3_FILEPATH "Resources/fbird3.png"
#define BIRD_FRAME4_FILEPATH "Resources/fbird4.png"
// шрифт для результатов игры
#define SCORE_FONT_FILEPATH "Resources/ScoreFont.ttf"
// заголовок при геймовере
#define TITLE_GAME_OVER_FILEPATH "Resources/Title-Game-Over.png"
// инфо по центру при геймовере
#define INFO_GAME_OVER_FILEPATH "Resources/Game-Over-Body.png"
// рисую медали
#define MEDAL_NONE_FILEPATH "Resources/MedalNone.png"
#define MEDAL_BRONZE_FILEPATH "Resources/MedalBronze.png"
#define MEDAL_SILVER_FILEPATH "Resources/MedalSilver.png"
#define MEDAL_GOLD_FILEPATH "Resources/MedalGold.png"
#define MEDAL_PLATINUM_FILEPATH "Resources/MedalPlatinum.png"
// для анимации птицы (время смены спрайтов)
#define BIRD_ANIMATION_DURATION 0.3f
// звуки в игре
#define SOUND_HIT_FILEPATH "Resources/Hit.wav"
#define SOUND_POINT_FILEPATH "Resources/Point.wav" 
#define SOUND_WING_FILEPATH "Resources/Wing.wav"
#define SOUND_COMLETE_FILEPATH "Resources/Complete.wav"
// состояния полёта птицы
#define BIRD_ONE_STILL 1 // текущее
#define BIRD_TWO_FALLING 2 // падение
#define BIRD_THREE_FLYING 3 // в процессе полёта
// сила притяжения
#define WORLD_GRAVITY 70.0f
// скорость полёта птицы
#define BIRD_FLY_SPEED 130.0f
// длительность полёта птицы
#define BIRD_FLY_DURATION 0.45f
// для смены направления полёта птицы (чуть-чуть меняю угол)
#define BIRD_FLIGHT_ANGLE 60.0f
// создаю перечисление для статусов игры
enum GameBirdStates
{
	eReady,
	ePlayGame,
	eGameOver
};
// вспышка при столкновении с поверхностью (красным)
#define GLOSS_FLASH_SPEED 1777.7f
// время при геймовере
#define TIME_BEFORE_GAME_OVER 0.7f
// количество очков для получения медали
#define SCORE_NONE_MEDAL 0
#define SCORE_BRONZE_MEDAL 20
#define SCORE_SILVER_MEDAL 50
#define SCORE_GOLD_MEDAL 80
#define SCORE_PLATINUM_MEDAL 110