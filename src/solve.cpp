#include "solve.hpp"
#include <stack>

Maze mazeFromInts(std::vector<std::vector<int>> nums)
{
    Maze m;
    for(unsigned long i = 0; i < nums.size(); i++)
        m.array.push_back(std::vector<Cell>());
    for (unsigned long i = 0; i < nums.size(); i++)
    {
        for (unsigned long j = 0; j < nums[i].size(); j++)
        {
            Cell c;
            switch(nums[i][j])
            {
            case 0:
                c.type = EMPTY_CELL;
                break;
            case 1:
                c.type = WALL_CELL;
                break;
            case 2:
                c.type = START_CELL;
                break;
            case 3:
                c.type = END_CELL;
                break;
            default:
                break;
            }
            m.array[i].push_back(c);
        }
    }
    return m;
}

std::vector<Coord> getAdjacent(Maze &m, Coord c)
{
    std::vector<Coord> vec;
    if(c.x > 0 && m.array[c.y][c.x - 1].type != WALL_CELL)
    {
        Coord tmp;
        tmp.x = c.x - 1;
        tmp.y = c.y; 
        vec.push_back(tmp);
    }
    if(c.x + 1 != (int)m.array[0].size() && m.array[c.y][c.x + 1].type != WALL_CELL)
    {
        Coord tmp;
        tmp.x = c.x + 1;
        tmp.y = c.y; 
        vec.push_back(tmp);
    }
    if(c.y > 0 && m.array[c.y - 1][c.x].type != WALL_CELL)
    {
        Coord tmp;
        tmp.x = c.x;
        tmp.y = c.y - 1; 
        vec.push_back(tmp);
    }
    if(c.y + 1 != (int)m.array.size() && m.array[c.y + 1][c.x].type != WALL_CELL)
    {
        Coord tmp;
        tmp.x = c.x;
        tmp.y = c.y + 1; 
        vec.push_back(tmp);
    }
    return vec;
}

Coord findCell(Maze &m, cellType t)
{
    for(int i = 0; i < (int)m.array.size(); i++)
    {
        for(int j = 0; j < (int)m.array[j].size(); j++)
        {
            if(m.array[i][j].type == t)
            {
                Coord c;
                c.x = j;
                c.y = i;
                return c;
            }
        }
    }
    return {.x = 0, .y = 0};
}

bool solve(Maze &m)
{
    std::stack<Coord> path;
    std::stack<Coord> decisions;
    return true;
}
