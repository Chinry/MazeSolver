#include <SFML/Window.hpp>
#include "input.hpp"
#include "solve.hpp"

bool pressed = false;

void updateCoord(Maze &m, Coord &c)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        if (pressed) return;
        if(c.x > 0)
        {
            c.x--;
        }
        pressed = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        if (pressed) return;
        if(c.x < m.array.size() - 1)
        {
            c.x++;
        }
        pressed = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        if (pressed) return;
        if(c.y > 0)
        {
            c.y--;
        }
        pressed = true;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        if (pressed) return;
        if(c.y < m.array[0].size() - 1)
        {
            c.y++;
        }
        pressed = true;
    }
    else
    {
        pressed = false;
    }
}

bool pressed2 = false;
void updateSelection(Maze &m, Coord &c)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
    {
        if (pressed2) return;
        switch(m.array[c.x][c.y].type)
        {
            case EMPTY_CELL:
                m.array[c.x][c.y].type = WALL_CELL;
            break;
            case WALL_CELL:
                if(!m.finishPlaced)
                {
                    m.array[c.x][c.y].type = END_CELL;
                    m.finishPlaced = true;
                }
                else if(!m.startPlaced)
                {
                    m.array[c.x][c.y].type = START_CELL;
                    m.startPlaced = true;
                }
                else m.array[c.x][c.y].type = EMPTY_CELL;
            break;
            case END_CELL:
                if(!m.startPlaced)
                {
                    m.array[c.x][c.y].type = START_CELL;
                    m.startPlaced = true;
                }
                else
                {
                    m.array[c.x][c.y].type = EMPTY_CELL;
                }
                m.finishPlaced = false;
            break;
            case START_CELL:
                m.startPlaced = false;
            default:
                m.array[c.x][c.y].type = EMPTY_CELL;    
        }
        pressed2 = true;
    }
    else pressed2 = false;
    
}

bool solved = false;

void updatePath(Maze &m)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !solved)
    {
        solve(m);
        solved = true;
    }
}



void Input::process(Maze &m, Coord &c)
{
    updatePath(m);
    updateSelection(m,c);
    updateCoord(m, c);
}