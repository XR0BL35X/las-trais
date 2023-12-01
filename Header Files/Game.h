#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

class Game
{
private:
    sf::RenderWindow* window;

//Private fuctions
    void initWindow();

public:
    Game();
    virtual ~Game();

    //Functions
    void run();

    void update();
    void render();
};
