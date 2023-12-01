#include "Game.h"

//Private functions 
void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Swaglords of Space - Ganme 3" , sf::Style::Close |  sf::Style::Titlebar );
    this->window.setFrameratelimit(144);
    this->window.setVerticalSyncEnabled(false);
}


//Con/Des
Game::Game()
{

}

Game::~Game()
{
    delete this->window;
}

//Fuctions
void Game::run()
{
    while (this->window->isOpen())
    {
        this->update();
        this->render();
    }
}

void Game::update()
{
    sf::Event e;
    while(this->pollEvent(e))
    {
        if(e.Event::type == sf::Event::closed)
        this->window->close();
    if(e.Event::KeyPressed && e.Event::key.code == sf::Keyboar::Escape)
        this->window->close();
    }
}

void Game::render()
{
    this->window->clear();

    //draw all the stuffs

//Draw all the stuffs

    this->window->display();
}