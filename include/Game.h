#pragma once

#include <map>
#include<Player.h>
#include<Bullet.h>
#include<Enemy.h>

class Game
{
private:
    //window
    sf::RenderWindow* window;

    //Resouces
    std::map<std::string, sf::Texture*> textures;
    std::vector<Bullet*> bullets;

    //Player
    Player* player;

    //Enemies
	float spawnTimer;
	float spawnTimerMax;
	std::vector<Enemy*> enemies;

    //Private fuctions
    void initWindow();
    void initPlayer();

    void initTextures();
    void initEnemies();

public:
    Game();
    virtual ~Game();

    //Functions
    void run();

    void updatePollEvents();
    void updateInput();
    void updateBullets();
    void updateEnemies();
    void update();
    void render();
};