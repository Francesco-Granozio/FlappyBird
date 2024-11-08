#pragma once
class State
{
public:
	virtual void Init() = 0;

	virtual void HandleInput() = 0;

	virtual void Update(float dt) = 0;

	virtual void Init(float dt) = 0;

	virtual void Pause() = 0;

	virtual void Resume() = 0;
};
