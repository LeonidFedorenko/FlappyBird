#pragma once
#include <memory> // память
#include <stack>
#include "State.hpp"

namespace SoundSonar //Sonar
{	// класс unique_ptr - средство управления ресурсом
	// typedef позволяет создать псевдоним для любого типа данных 
	typedef std::unique_ptr<State> StateRef; // текущее состояние

	class GameMashine //StateMashine
	{
	public: // конструктор
		GameMashine() { }
		// деструктор
		~GameMashine() { }

		// обновляю состояние игры
		void AddState(StateRef newState, bool isReplacing = true);
		// убираю состояние
		void RemoveState();

		// изменяю статус игры
		void ProcessStateChanges();

		StateRef &GetActivateState();

	private:
		std::stack<StateRef> _states; // все статусы игры
		StateRef _newState; // новый статус
		// операции со статусами
		bool _isRemoving;
		bool _isAdding;
		bool _isReplacing;
	};
}
