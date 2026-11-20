#include <grid.hpp>

Grid::Grid() : cells(rows, std::vector<Cell>(cols)) {
    
};


void Grid::draw(sf::RenderWindow& window) {
    for (const auto& row : cells) {
        for (const auto& cell : row) {
            sf::RectangleShape rectangle(sf::Vector2f(cellSize, cellSize));
            rectangle.setPosition(cell.position);
            if (cell.isWall) {
                rectangle.setFillColor(sf::Color::Black);
            } else {
                rectangle.setFillColor(sf::Color::White);
            }
            window.draw(rectangle);
        }
    }
}

void Grid::setCell() {
    std::vector<std::string> level = level1; 
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            Cell& cell = Grid::cells[row][col];
            cell.position = sf::Vector2f(col * cellSize, row * cellSize);
            if (level[row][col] == '#') {
                cell.isWall = true;
            }
        }
    }
}

void Grid::checkWalls() {
    for (int row = 0; row < rows; ++row) {
        for (int col = 0; col < cols; ++col) {
            
        }
    }
}