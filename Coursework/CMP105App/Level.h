#pragma once

#include "Framework/BaseLevel.h"
#include "Framework/GameObject.h"
#include "Player.h"

class Level : BaseLevel {
public:
	Level(sf::RenderWindow& window, Input& input);
	~Level() override = default;

	void handleInput(float dt) override;
	void update(float dt);
	void render();

private:
	// Default functions for rendering to the screen.

	// Default variables for level class.
	
	sf::CircleShape m_snake;
	

	Player m_sheep;
	sf::Texture m_sheepTexture;

};