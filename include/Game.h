#pragma once

#include <map>
#include<Player.h>
#include<Bullet.h>

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

//Private fuctions
    void initWindow();
    void initPlayer();

    void initTextures();

public:
    Game();
    virtual ~Game();

    //Functions
    void run();

    void updatePollEvents();
    void updateInput();
    void updateBullets();
    void update();
    void render();
};
