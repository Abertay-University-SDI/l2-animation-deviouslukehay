#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	m_sheep.setInput(&m_input);
	m_sheep.setWindow(&m_window);
	m_sheep.setPosition({ 200,200 });
	m_sheep.setSize({ 64,64 });

	m_worm.setInput(&m_input);
	m_worm.setWindow(&m_window);
	m_worm.setPosition({ 0, 534 });
	m_worm.setSize({ 64,64 });

	if (!m_sheepTexture.loadFromFile("gfx/sheep_sheet.png")) std::cerr << "Sheep spritesheet failed to load!" << std::endl;
	if (!m_wormTexture.loadFromFile("gfx/worm_sheet.png")) std::cerr << "Worm spritesheet failed to load!" << std::endl;

	sf::IntRect texture_rect({ 64,64 }, { 0,0 });

	m_sheep.setTexture(&m_sheepTexture, true);
	m_sheep.setTextureRect(texture_rect);

	m_worm.setTexture(&m_wormTexture, true);
	m_worm.setTextureRect(texture_rect);
}

// handle user input
void Level::handleInput(float dt)
{
	if (m_sheep.getGameOver()) return;

	m_sheep.handleInput(dt);
	
}

// Update game objects
void Level::update(float dt)
{
	if (m_worm.getTimerExpired())
		m_sheep.setGameOver(true);

	if (m_sheep.getGameOver()) return;

	m_worm.update(dt);
	m_sheep.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	m_window.draw(m_worm);
	m_window.draw(m_sheep);
	endDraw();
}

