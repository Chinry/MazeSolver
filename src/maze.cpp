#include "maze.hpp"
void Maze::resetMarked()
{
    path = std::vector<Coord>();
    for(int i = 0; i < (int)array.size(); i++)
    {
        for(int j = 0; j < (int)array[i].size(); j++)
        {
            array[i][j].marked = false;
        }
    }
}

void Maze::setSize(int x, int y)
{
    array.resize(y);
    for (int i = 0; i < y; i++)
        array[i].resize(x,{.type = EMPTY_CELL});
    resetMarked();
}