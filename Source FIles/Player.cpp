#include "Player.h"

    void Player::initTexture();
    {
        //load a texture from file
    }

    void Player::initSprite();
    {
        //set the Texture to the spite 
        this->sprite.setTexture(this->texture);
    }
    Player::Player()
    {
        this->initTexture();
        this->initSprite();
    }

     Player::~Player()
    {

    }

    //funciones
    void Player::update()
    {
    }

    void Player::render(sf::RenderTarget &targe)
    {
        target.draw(this->sprite);
    }
