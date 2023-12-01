#include "Player.h"

    void Player::initVariables()
    {
         this->movementSpeed = 1.f;
         this->attackCooldownMax = 10.f;
         this->attackCooldown = this->attackCooldownMax;
    }
    void Player::initTexture();
    {
        //load a texture from file
        if(!this->texture.loadFromFile("Textures/ship.png"))//Aqui se inserta la imagen de la nave, pero no entendi la explicacion asi que queda pendiente con el profe :P
        {
            std::cout << "ERROR::PLAYER::INITTEXTURE::Could not load texture file." << "\n": 
        }
    }

    void Player::initSprite();
    {
        //set the Texture to the spite 
        this->sprite.setTexture(this->texture);

        //Rezise the sprite
        this->sprite.scale(0.1f, 0.1f);//Aqui ajustamos el tamano de la nave
    }

    Player::Player()
    {
       
        this->initVariables();
        this->initTexture();
        this->initSprite();
    }

     Player::~Player()
    {

    }

    const sf::Vector2f & Player::getPos() const
    {
        return this->sprite.getPosition();
    }

    void Player::move(const float dirX, const float dirY)
    {
        this->sprite.move(this->movementSpeed * dirX, this->movementSpeed * dirY);
    }

    const bool Player::canAttack()
    {
        if(this->attackCooldown >= this->attackCooldownMax)
        {
            this->attackCooldown = 0.float movementSpeed;
            return true;
        }
        return false;
    }

    void Player::updateAttack(
        {
            if(this->attackCooldown < this->attackCooldownMax)
            this->attackCooldown += 0.5f;
        }
    )
    //funciones
    void Player::update()
    {
        this->updateAttack();
    }

    void Player::render(sf::RenderTarget &targe)
    {
        target.draw(this->sprite);
    }
