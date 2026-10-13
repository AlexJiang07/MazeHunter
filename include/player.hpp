#pragma once
#include <SFML/Graphics.hpp>


class Player {
    public:
        Player();
        void drawPlayer(sf::RenderWindow& window);//, sf::Sprite& playerSprite);
        void movePlayer(sf::Vector2f direction,float deltaTime);//, sf::Sprite& playerSprite);
        void handlePlayerInput(sf::Keyboard::Key key, sf::Sprite& playerSprite);
        sf::Vector2f getPosition() { return position; }
    private:
        sf::CircleShape circle{25.f};
        float speed = 100.f;
        sf::Vector2f position;
        float width = 50.f;
        float height = 50.f;
};
