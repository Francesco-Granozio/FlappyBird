#include "StateStack.h"

void StateStack::addState(std::unique_ptr<State> newState, bool isReplacing) {

	this->m_IsAdding = true;
	this->m_IsReplacing = isReplacing;
	this->m_NewState = std::move(newState);
}


void StateStack::removeState() {

	this->m_IsRemoving = true;
}


void StateStack::processStateChanges() {

	if (this->m_IsRemoving && !this->m_States.empty()) {

		this->m_States.pop();

		if (!this->m_States.empty()) {

			this->m_States.top()->resume();
		}

		this->m_IsRemoving = false;

	}

	if (this->m_IsAdding) {

		if (!this->m_States.empty()) {

			if (this->m_IsReplacing) {

				this->m_States.pop();
			}
			else {

				this->m_States.top()->pause();
			}
		}

		this->m_States.push(std::move(this->m_NewState));
		this->m_States.top()->init();
		this->m_IsAdding = false;
	}
}

std::unique_ptr<State>& StateStack::getActiveState() {

	return this->m_States.top();
}