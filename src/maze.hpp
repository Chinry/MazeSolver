#include <vector>

enum cellType
{
    END_CELL, START_CELL, WALL_CELL, EMPTY_CELL
};

struct Cell
{
    enum cellType type;
};

struct Maze
{
    std::vector<std::vector<Cell>> array;
    std::vector<std::vector<Cell>> path;
    bool finishPlaced = false;
    bool startPlaced = false;
};