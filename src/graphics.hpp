#pragma once
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "maze.hpp"

class Graphics
{
public:
    bool isOpen();
    void process(Maze &m, Coord &c);
    Graphics(int x, int y);
private:
    sf::RenderWindow window;
    void drawGrid(Maze &m);
    void drawCursor(Coord &c);
    void drawPath(Maze &m);
};