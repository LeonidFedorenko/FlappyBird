#include "GameMashine.hpp"

namespace SoundSonar
{	// метод для изменения статуса игры 
	void GameMashine::AddState(StateRef newState, bool isReplacing)
	{
		this->_isAdding = true;
		this->_isReplacing = isReplacing;
		// замена
		this->_newState = std::move(newState);
	}

	void GameMashine::RemoveState()
	{	// готово к удалению
		this->_isRemoving = true;
	}

	void GameMashine::ProcessStateChanges()
	{
		if (this->_isRemoving && !this->_states.empty())
		{
			this->_states.pop();
			if (!this->_states.empty())
			{
				this->_states.top()->Resume();
			}

			this->_isRemoving = false; // запрет
		}

		if (this->_isAdding)
		{	// если не пусто
			if (!this->_states.empty())
			{
				if (this->_isReplacing)
				{	// можно поменять
					this->_states.pop();
				}
				else // в другом случае (pause)
				{
					this->_states.top()->Pause();
				}
			}
			// установка нового статуса
			this->_states.push(std::move(this->_newState));
			this->_states.top()->Init();
			// после запрет добавления
			this->_isAdding = false;
		}
	}
	// смена статуса игры
	StateRef &GameMashine::GetActivateState()
	{
		return this->_states.top();
	}
}