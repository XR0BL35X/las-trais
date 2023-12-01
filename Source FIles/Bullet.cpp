#include "Bullet.h"

    Bullet::Bullet()
    {

    }
    
    Bullet(sf::Texture & texture, float dir_x, float dir_y, float movementSpeed);
    {
        this->shape.setTexture(texture);
        this->dirction.x = dir_x;
        this->dirction.y = dir_y;
        this->movementSpeed = movement_speed;
    }

    Bulet::~Bullet()
    {
    }

    void Bullet::update()
    {
        //movimiento
        this->shape.move(this->movementSpeed * this->direction);
    }

    void Bullet::render(sf::RenderTarget * target)
    {
        target->draw(this.shape);
    }

