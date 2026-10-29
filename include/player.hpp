#pragma once
#include <SFML/Graphics.hpp>


class Player {
    public:
        Player();
        void drawPlayer(sf::RenderWindow& window);//, sf::Sprite& playerSprite);
        void movePlayer(sf::Vector2f direction,float deltaTime);//, sf::Sprite& playerSprite);
        void handlePlayerInput(sf::Keyboard::Key key, sf::Sprite& playerSprite);
        sf::Vector2f getPosition() const { return position; }
        
        float getwidth() const { return width; }
        float getheight() const { return height; }
        //bool getIsDead() const { return isDead; }
        //void setIsDead(bool dead) { isDead = dead; }
    private:
        //bool isDead = false;
        sf::Texture playerTexture;
        sf::Sprite playerSprite;
        float speed = 100.f;
        sf::Vector2f position;
        float width = 64.f;
        float height = 64.f;
};
