#pragma once

#include <memory>
#include <stack>

#include "State.h"

class StateStack
{

public:

	StateStack() {

	}

	~StateStack() {

	}

	void AddState(std::unique_ptr<State> newState, bool isReplacing = true);

	void RemoveState();

	void ProcessStateChanges();

	std::unique_ptr<State>& GetActiveState();

private:
	std::stack <std::unique_ptr<State>> m_States;
	std::unique_ptr<State> m_NewState;
	bool m_IsRemoving;
	bool m_IsAdding;
	bool m_IsReplacing;
};

