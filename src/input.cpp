#include <SFML/Window.hpp>
#include "input.hpp"

void updateCoord(Maze &m, Coord &c)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if(c.x > 0)
        {
            c.x--;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if(c.x < m.array.size() - 1)
        {
            c.x++;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if(c.y > 0)
        {
            c.y--;
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if(c.y < m.array[0].size() - 1)
        {
            c.y++;
        }
    }
}

void updateSelection(Maze &m, Coord &c)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        switch(m.array[c.y][c.x].type)
        {
            case EMPTY_CELL:
                m.array[c.y][c.x].type = WALL_CELL;
            break;
            case WALL_CELL:
                if(!m.finishPlaced)
                {
                    m.array[c.y][c.x].type = END_CELL;
                    m.finishPlaced = true;
                }
            break;
            case END_CELL:
                if(!m.startPlaced)
                {
                    m.array[c.y][c.x].type = START_CELL;
                    m.startPlaced = true;
                }
                m.finishPlaced = false;
            break;
            case START_CELL:
                m.startPlaced = false;
            default:
                m.array[c.y][c.x].type = EMPTY_CELL;
                
        }
    }
}


void Input::process(Maze &m, Coord &c)
{
    updateCoord(m, c);
    updateSelection(m,c);
}