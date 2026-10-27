#include <enemy.hpp>
#include <player.hpp>

Enemy::Enemy(const Player& player): p1(player) {
    position = sf::Vector2f(100.f, 200.f);
    circle.setPosition(position);
    circle.setFillColor(sf::Color::Red);
}

void Enemy::drawEnemy(sf::RenderWindow& window) {
    window.draw(circle);
}

void Enemy::moveEnemy(sf::Vector2f direction, float deltaTime) {
    position += direction * speed * deltaTime;
    circle.setPosition(position);
}

void Enemy::handleEnemyInput(sf::Keyboard::Key key, sf::Sprite& enemySprite) {

}

void Enemy::aiMove(float deltaTime) {
    sf::Vector2f playerPosition = p1.getPosition();
    /*
    sf::Vector2f direction(0.f, 0.f);
    if (rand() % 2 == 0) {
        direction.x = (rand() % 3 - 1); // -1, 0, or 1
    } else {
        direction.y = (rand() % 3 - 1); // -1, 0, or 1
    }
    moveEnemy(direction, deltaTime);
    */
}
