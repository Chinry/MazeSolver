#include "maze.hpp"
#include <vector>

struct Coord
{
    int x;
    int y;
};
bool solve(Maze &m);
Maze mazeFromInts(std::vector<std::vector<int>> nums);
std::vector<Coord> getAdjacent(Maze &m, Coord c);
Coord findCell(Maze &m, cellType t);
