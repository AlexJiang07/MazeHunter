#pragma once
#include <SFML/Graphics.hpp>
#include "player.hpp"

class Enemy {
public:
    Enemy(const Player& player);
    //non defined
    void drawEnemy(sf::RenderWindow& window);
    void moveEnemy(sf::Vector2f direction,float deltaTime);
    void handleEnemyInput(sf::Keyboard::Key key, sf::Sprite& enemySprite);
    void aiMove(float deltaTime);
    void checkDefeat();
    //defined
    sf::Vector2f getPosition() { return position; }
    void setPosition(sf::Vector2f newPosition) { position = newPosition; circle.setPosition(position); }
    void setDefeatedPlayer(bool defeated) { defeatedPlayer = defeated; }
    bool getDefeatedPlayer() const { return defeatedPlayer; }
private:
    bool defeatedPlayer = false;
    const Player& p1;
    sf::Vector2f position;
    sf::CircleShape circle{25.f};
    float speed = 50.f;
    float width = 25.f;
    float height = 25.f;
};