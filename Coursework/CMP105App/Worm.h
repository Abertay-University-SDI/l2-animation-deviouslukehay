#pragma once

#include "Framework/GameObject.h"
#include "Framework/Animation.h"

class Worm : public GameObject {

public:

	Worm();
	virtual ~Worm() = default;

	void update(float dt) override;

	float getTimer();
	void setTimer(float dt);

	bool getTimerExpired();
	void setTimerExpired(bool expired);

private:

	float m_speed = 24.5333f; //weird number, makes the timer accurate for 30s
	float m_timer = 0.f;
	float m_timerEnd = 30.f;
	bool m_timerExpired = false;

	Animation m_wormingForwards;
	Animation* m_currentAnim;

};