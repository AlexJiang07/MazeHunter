#pragma once
#include <SFML/Graphics.hpp>

class Grid {
    public:
        struct Cell {
            sf::Vector2f position;
            bool isWall;
            bool northWall;
            bool southWall;
            bool eastWall;
            bool westWall;
        };
        Grid();
        void draw(sf::RenderWindow& window);
    private:
        int cellSize = 32.f;
        std::vector<std::vector<Cell>> cells;
};