#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "player.hpp"
#include "enemy.hpp"
#include "grid.hpp"
using namespace sf;



int main() {
    sf::Clock clock;
    Player player;
    Enemy enemy(player);
    Grid grid;
    grid.setCell();
    RenderWindow window(VideoMode({896, 768}), "Maze Hunter");
    while (window.isOpen()){
        float deltaTime = clock.restart().asSeconds();
        window.clear(sf::Color::Black);
        while (const auto event = window.pollEvent()){
            if (event->is<sf::Event::Closed>()){
               window.close();
            }
        }
        enemy.checkDefeat();
        if(enemy.getDefeatedPlayer()) {
            std::cout << "Player has been defeated by the enemy!" << std::endl;
            window.close();
        }
        grid.draw(window);
        enemy.aiMove(deltaTime);
        enemy.drawEnemy(window);
        player.movePlayer(player.getPosition(), deltaTime);
        player.drawPlayer(window);
        window.display();
    }
    return 0;
}
