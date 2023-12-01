#pragma once

#include <map>
#include"Player h"
#include"Bullet.h"

class Game
{
private:
    //Window
    sf::RenderWindow* window;

    //Resouces
    std::map<std::string, sf::Texture> textures;
    std::vector<Bullet*> bullet;

    //Player
    Player* player;
    
    //Private fuctions
    void initWindow();
    void initTextures();

    void initPlayer();

public:
    Game();
    virtual ~Game();

    //Functions
    void run();
    
    void updatePollEvents();
    void updateinput();
    void updateBullets();
    void update();
    void render();
};
