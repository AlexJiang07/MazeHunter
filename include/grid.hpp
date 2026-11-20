#pragma once
#include <SFML/Graphics.hpp>
#include <levels.hpp>

class Grid {
    public:
        struct Cell {
            sf::Vector2f position;
            bool isWall = false;
            bool northWall;
            bool southWall;
            bool eastWall;
            bool westWall;
        };
        Grid();
        void draw(sf::RenderWindow& window);
        void setCell();
        void checkWalls();
    private:
        int rows = 24;
        int cols = 28;
        int cellSize = 32.f;
        std::vector<std::vector<Cell>> cells;
};