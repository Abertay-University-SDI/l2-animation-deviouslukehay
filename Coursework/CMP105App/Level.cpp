#include "Level.h"

Level::Level(sf::RenderWindow& hwnd, Input& in) :
	BaseLevel(hwnd, in)
{
	m_sheep.setInput(&m_input);
	m_sheep.setWindow(&m_window);
	m_sheep.setPosition({ 200,200 });

	m_sheep.setSize({64,64});

	if (!m_sheepTexture.loadFromFile("gfx/sheep_sheet.png")) std::cerr << "Sheep spritesheet failed to load!" << std::endl;
	
	int row = 0;
	int col = 0;

	GameObject new_sheep_texture;

	sf::IntRect texture_rect({ row * 64, col * 64 }, { 64,64 });

	m_sheep.setTexture(&m_sheepTexture, true);
	m_sheep.setTextureRect(texture_rect);
	
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
	if (m_sheep.getGameOver()) return;

	m_sheep.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	m_window.draw(m_sheep);
	endDraw();
}

