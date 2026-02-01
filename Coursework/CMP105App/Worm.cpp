#include "Worm.h"

Worm::Worm() {

	for (int i = 0; i < 6; i++) {

		sf::IntRect texture_rect({ i * 64, 0 }, { 64,64 });

		m_wormingForwards.addFrame(texture_rect);
	}

	m_wormingForwards.setFrameSpeed(1.f / 8.f);
	m_wormingForwards.setLooping(true);

	m_currentAnim = &m_wormingForwards;
	setTextureRect(m_currentAnim->getCurrentFrame());
}

void Worm::update(float dt) {
	m_currentAnim->animate(dt);
	setTextureRect(m_currentAnim->getCurrentFrame());
	setTimer(dt);
	if (m_timer < m_timerEnd)
		move({ m_speed * dt, 0.f });
	else
		setTimerExpired(true);
}

float Worm::getTimer() {
	return m_timer;
}

void Worm::setTimer(float dt) {
	m_timer += dt;
}

bool Worm::getTimerExpired() {
	return m_timerExpired;
}

void Worm::setTimerExpired(bool expired) {
	m_timerExpired = expired;
}