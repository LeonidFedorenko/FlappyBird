#pragma once

namespace SoundSonar
{ // определение звука
	class State
	{ // текущее состояние
	public: // публичное состояние
		virtual void Init() = 0; // для инициализации

		virtual void HandleInput() = 0; // обработка ввода от игрока

		virtual void Update(float dt) = 0; // обновление

		virtual void Draw(float dt) = 0; // для прорисовки

		virtual void Pause() {} // для паузы

		virtual void Resume() {}// для повторения/возврата
	};
}