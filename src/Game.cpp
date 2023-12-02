#include <Game.h>


//Private functions 
void Game::initWindow()
{
    this->window = new sf::RenderWindow(sf::VideoMode(800, 600), "Swaglords of Space - Ganme 3" , sf::Style::Close |  sf::Style::Titlebar );
    this->window.setFrameratelimit(144);
    this->window.setVerticalSyncEnabled(false);
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
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
       this->player->move(-1.f, 0.f);
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
       this->player->move(1.f, 0.f); 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
       this->player->move(0.f, -1.f); 
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
       this->player->move(0.f, 1.f); 

    if (sf::Mouse::isButtonPressed(sf::Mouse::Left) && this->player->canAtack())
    {
        this->bullets.push_back(new Bullet(this->textures["BULLET"],this->player->getPos().x, this->player->getPos().y, 0.f, -1.f, 5.f));
    }   
}

void Game::updateBullets()
    {
        unsigned counter = 0;
        for (auto *Bullet : this->bullets)
        {
            bullet->update();
            //bullet culling (top of screen)
            if(bullet->getBounds().top + bullet->getBounds().height < 0.f)
            {  
                 //delete bullet
                delete bullet;
                this->bullets.erase(this->bullets.begin() + counter);
                --counter;  

                std::cout << this->bullets.size() <<"\n";      
            }
            ++counter
        }
    }

void Game::update()
    {
        this->updatePollEvents();

        this->updateInput();

        this->player->update();

        this->updateBullets();
    }

void Game::render()
{
    this->window->clear();

    //Draw all the stuffs
    this->player->render(*this->window);

    for (auto *Bullet : this->bullets)
    {
      bullet->render(this->window);
    }

    this->window->display();
}