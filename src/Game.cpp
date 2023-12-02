#include <Game.h>

//Private functions 
void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Swaglords of Space - Ganme 3" , sf::Style::Close |  sf::Style::Titlebar );
    this->window->setFramerateLimit(144);
    this->window->setVerticalSyncEnabled(false);
}

void Game::initTextures()
{
    this->textures["BULLET"] = new sf::Texture();
    this->textures["BULLET"]->loadFromFile("Textures/bullet.png");//Aqui se pone la imagen del el poryectil.
}

void Game::initPlayer()
{
    this->player = new Player();
}

//Con/Des
Game::Game()
{
    this->initWindow();
    this->initTextures();
    this->initPlayer();

}

Game::~Game()
{
    delete this->window;
    delete this->player;

    //Delete textures
    for (auto &i : this->textures)
    {
       delete i.second;
    }

    //Delete bullets
    for (auto *i : this->bullets)
    {
        delete i;
    }
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

void Game::updatePollEvents()
{
  sf::Event e;
    while(this->window->pollEvent(e))
    {
        if(e.Event::type == sf::Event::Closed)
        this->window->close();
    if(e.Event::KeyPressed && e.Event::key.code == sf::Keyboard::Escape)
        this->window->close();
    }
}

void Game::updateInput()
{
        //Move player
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
       this->player->move(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
       this->player->move(1.f, 0.f); 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
       this->player->move(0.f, -1.f); 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
       this->player->move(0.f, 1.f); 

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) 
    {

    this->bullets.push_back(new Bullet(this->textures["BULLET"], this->player->getPos().x, this->player->getPos().y,0.f,0.f,0.f,0.f));
      
    }  
}




void Game::updateBullets()
    {
        for (auto *bullet : this->bullets)
        {
            bullet->update();
        }

    }

void Game::update()
    {
    this->updatePollEvents();

    this->updateInput();

    this->updateBullets();
    }
void Game::render()
    
{
    this->window->clear();

//Draw all the stuffs
    this->player->render(*this->window);

    for (auto *bullet : this->bullets)
    {
      bullet->render(this->window);
    }

    this->window->display();
}