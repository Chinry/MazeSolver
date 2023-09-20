#include <SFML/Graphics.hpp>
#include "graphics.hpp"

Graphics::Graphics(int x, int y)
{
    window.setSize(sf::Vector2u(x*20, y*20));
    window.setTitle("Maze");
}

bool Graphics::isOpen()
{
   return window.isOpen();
}

void Graphics::drawGrid(Maze &m)
{
    sf::RectangleShape square(sf::Vector2f(20.f, 20.f));
    for(int i = 0; i < m.array.size(); i++)
    {
        for(int j = 0; j < m.array[j].size(); j++)
        {
            switch(m.array[i][j].type)
            {
                case WALL_CELL:
                    square.setFillColor(sf::Color(0,0,0));
                break;
                case END_CELL:
                    square.setFillColor(sf::Color(255,0,0));
                break;
                case START_CELL:
                    square.setFillColor(sf::Color(0,255,0));
                break;
                default:
                break;
            }
            if(m.array[i][j].type != EMPTY_CELL)
            {
                square.setPosition(i * 20.f, j * 20.f);
                window.draw(square);
            }
        }
    }
}

void Graphics::drawCursor(Coord &c)
{
    sf::RectangleShape curs(sf::Vector2f(20.f, 20.f));
    curs.setFillColor(sf::Color(255,255,255));
    curs.setOutlineColor(sf::Color(0,0,255));
    curs.setOutlineThickness(5.f);
    curs.setPosition(c.x * 20, c.y * 20);
    window.draw(curs);
}

void Graphics::process(Maze &m, Coord &c)
{
    drawGrid(m);
    drawCursor(c);
}
