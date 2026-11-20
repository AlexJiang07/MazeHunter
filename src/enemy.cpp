#include <enemy.hpp>
#include <player.hpp>

Enemy::Enemy(const Player& player): p1(player) {
    position = sf::Vector2f(100.f, 400.f);
    circle.setPosition(position);
    circle.setOrigin({16.f, 16.f});
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
    sf::Vector2f diff = playerPosition - position;
    setPosition(position + diff * speed * deltaTime / std::sqrt(diff.x * diff.x + diff.y * diff.y));
}

void Enemy::checkDefeat() {
    if (p1.getPosition().x - 32 <= position.x + width && p1.getPosition().x + 32  >= position.x - width &&
        p1.getPosition().y - 32 <= position.y + height && p1.getPosition().y + 32 >= position.y - height) {
        setDefeatedPlayer(true);
    }
}