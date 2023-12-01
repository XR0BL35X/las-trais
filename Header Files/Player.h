#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>

class Player
{
    private:
    sf::Sprite sprite;
    sf::Texture texture;

    
    //funciones
    void initTexture();
    void initSprite();
    public:
    Player();
    virtual ~Player();
    //funciones
    void update();
    void render(sf::RenderTarget &target);
}