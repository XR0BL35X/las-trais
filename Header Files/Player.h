#pragma once


class Player
{
    private:
        sf::Sprite sprite;
        sf::Texture texture;

        float movementSpeed;

        float attackCooldown;
        float attackCooldownMax;
        //funciones privadas
        void initVariables();
        void initTexture();
        void initSprite();

    public:
        Player();
        virtual ~Player();
        
        //Accessor
        const sf::Vector2f& getPos() const;

        //funciones
        void move(const float dirX, const float dirY);
        const bool canAttack();

        void updateAttack();
        void update();
        void render(sf::RenderTarget &target);
}