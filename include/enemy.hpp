#pragma once
#include <SFML/Graphics.hpp>
#include "player.hpp"

class Enemy {
public:
    Enemy(const Player& player);
    void drawEnemy(sf::RenderWindow& window);
    void moveEnemy(sf::Vector2f direction,float deltaTime);
    void handleEnemyInput(sf::Keyboard::Key key, sf::Sprite& enemySprite);
    void aiMove(float deltaTime);
    sf::Vector2f getPosition() { return position; }
private:
    const Player& p1;
    sf::Vector2f position;
    sf::CircleShape circle{25.f};
    float speed = 100.f;
    float width = 50.f;
    float height = 50.f;
};