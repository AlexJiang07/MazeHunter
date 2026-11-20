#include <iostream>
#include <string>  
#include "player.hpp"

Player::Player():playerTexture("../assets/PlayerProt0_1.png"), playerSprite(playerTexture)
{
    position = sf::Vector2f(100.f, 100.f);
    playerSprite.setPosition(position);
    playerSprite.setOrigin({32.f, 32.f});
    playerSprite.setColor(sf::Color::White);
}

void Player::movePlayer(sf::Vector2f direction,float deltaTime) {
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::W))
    {
        position += sf::Vector2f(0.0f, -speed * deltaTime);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::S))
    {
        position += sf::Vector2f(0.0f, speed * deltaTime);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A))
    {
        position += sf::Vector2f(-speed * deltaTime, 0.0f);
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D))
    {
        position += sf::Vector2f(speed * deltaTime, 0.0f);
    }
}

void Player::handlePlayerInput(sf::Keyboard::Key key, sf::Sprite& playerSprite) {
    sf::Vector2f direction(0.f, 0.f);
    if (key == sf::Keyboard::Key::W) {
        direction.y -= 1.f; // Move up
    } else if (key == sf::Keyboard::Key::S) {
        direction.y += 1.f; // Move down
    } else if (key == sf::Keyboard::Key::A) {
        direction.x -= 1.f; // Move left
    } else if (key == sf::Keyboard::Key::D) {
        direction.x += 1.f; // Move right
    }
    //movePlayer(direction, playerSprite);
}

//function void updatePlayer(sf::Sprite& playerSprite) {
    // Update player state, animations, etc.
//}
void Player::drawPlayer(sf::RenderWindow& window){//, sf::Sprite& playerSprite) {
    playerSprite.setPosition(position);
    window.draw(playerSprite);
}

//void handlePlayerCollision(sf::Sprite& playerSprite, const sf::FloatRect& obstacleBounds) {
    //if (playerSprite.getGlobalBounds().intersects(obstacleBounds)) {
        // Handle collision response (e.g., stop movement, bounce back, etc.)
    //}
//}
/*void resetPlayerPosition(sf::Sprite& playerSprite, const sf::Vector2f& startPosition) {
    playerSprite.setPosition(startPosition);
}*/