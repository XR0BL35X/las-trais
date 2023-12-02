#include <Player.h>

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
        this->movementSpeed = 1.f;

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

    //funciones
    void Player::update()
    {
    }

    void Player::render(sf::RenderTarget &targe)
    {
        target.draw(this->sprite);
    }
