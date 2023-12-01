#include "Game.h"

//Private functions 
void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Swaglords of Space - Ganme 3" , sf::Style::Close |  sf::Style::Titlebar );
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

}

void Game::render()
{
    this->window->clear();

//Draw all the stuffs

    this->window->display();
}