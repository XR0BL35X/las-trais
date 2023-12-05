#pragma once

#include <map>
#include <string>
#include <sstream>
#include "Player.h"
#include "Bullet.h"
#include "Enemy.h"

class Game
{
private:
	// window
	sf::RenderWindow *window;

	// Resouces
	std::map<std::string, sf::Texture *> textures;
	std::vector<Bullet *> bullets;

	// GUI
	sf::Font font;
	sf::Text pointText;

	sf::Text gameOverText;

	// World
	sf::Texture worldBackgroundTex;
	sf::Sprite worldBackground;

	// Systems
	unsigned points;

	// Player
	Player *player;

	// PlayerGUI
	sf::RectangleShape playerHpBar;
	sf::RectangleShape playerHpBarBack;

	// Enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy *> enemies;

	// Private fuctions
	void initWindow();
	void initTextures();
	void initGUI();
	void initWorld();
	void initSystems();

	void initPlayer();
	void initEnemies();

public:
	Game();
	virtual ~Game();

	// Functions
	void run();

	void updatePollEvents();
	void updateInput();
	void updateGUI();
	void updateWorld();
	void updateCollision();
	void updateBullets();
	void updateEnemies();
	void updateCombat();
	void update();

	void renderGUI();
	void renderWorld();
	void render();
};