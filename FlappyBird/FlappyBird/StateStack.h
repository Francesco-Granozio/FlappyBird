#pragma once

#include <memory>
#include <stack>

#include "State.h"

class StateStack
{

public:

	StateStack() : 
		m_IsRemoving(false), m_IsAdding(false), m_IsReplacing(false) { }
	~StateStack() { }
	void addState(std::unique_ptr<State> newState, bool isReplacing = true);
	void removeState();
	void processStateChanges();
	std::unique_ptr<State>& getActiveState();

private:
	std::stack <std::unique_ptr<State>> m_States;
	std::unique_ptr<State> m_NewState;
	bool m_IsRemoving;
	bool m_IsAdding;
	bool m_IsReplacing;
};

