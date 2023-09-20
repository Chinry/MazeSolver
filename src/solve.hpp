#pragma once

#include "maze.hpp"
#include <vector>


bool solve(Maze &m);
Maze mazeFromInts(std::vector<std::vector<int>> nums);
std::vector<Coord> getAdjacent(Maze &m, Coord c);
Coord findCell(Maze &m, cellType t);
