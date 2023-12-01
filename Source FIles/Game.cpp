#include "Game.h"

//Private functions 
void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Swaglords of Space - Ganme 3" , sf::Style::Close |  sf::Style::Titlebar );
    this->window.setFrameratelimit(144);
    this->window.setVerticalSyncEnabled(false);
}

void Game::initPlayer()
{
    this->player = new Player();
}

//Con/Des
Game::Game()
{
    this->initWindow();
    this->initPlayer();
}

Game::~Game()
{
    delete this->window;
    delete this->player;
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

     void Game::updatePollEvents();
     {
        
    sf::Event e;
    while(this->window->pollEvent(e))
    {
        if(e.Event::type == sf::Event::closed)
        this->window->close();
        if(e.Event::KeyPressed && e.Event::key.code == sf::Keyboar::Escape)
        this->window->close();
    }
     }

     void Game::updateinput();
     {
        
    //Move player
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::A))
       this->player->move(-1.f, 0.f);
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::D))
       this->player->move(1.f, 0.f); 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::W))
       this->player->move(0.f, -1.f); 
    if(sf::Keyboard::isKeyPressed(sf::Keyboard::S))
       this->player->move(0.f, 1.f); 
     }

void Game::update()
    {
        this->updatePollEvents();

        this->updateinput();
   
    }

       
        

}

void Game::render()
{
    this->window->clear();

    //Draw all the stuffs
    this->player->render(*this->window);

    this->window->display();
}