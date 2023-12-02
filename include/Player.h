#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<iostream>

class Player
{
private:
    sf::Sprite sprite;
    sf::Texture texture;

    float movementSpeed;

    //Private functions
    void initTexture();
    void initSprite();

public:
    Player();
    virtual ~Player();

     //Accessor
    const sf::Vector2f& getPos() const;

    //funciones
    void move(const float dirX, const float dirY);
    void update();
    void render(sf::RenderTarget& target);
};