#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "player.hpp"
#include "enemy.hpp"
using namespace sf;



int main() {
    sf::Clock clock;
    Player player;
    Enemy enemy(player);
    RenderWindow window(VideoMode({1200, 1000}), "Maze Hunter");
    while (window.isOpen()){
        float deltaTime = clock.restart().asSeconds();
        window.clear(sf::Color::Black);
        while (const auto event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()){
               window.close();
            }
        }
        enemy.drawEnemy(window);
        player.movePlayer(player.getPosition(), deltaTime);
        player.drawPlayer(window);
        window.display();
    }
    return 0;
}
