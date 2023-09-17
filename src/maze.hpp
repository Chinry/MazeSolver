#include <vector>

struct Coord
{
    int x;
    int y;
};

enum cellType
{
    END_CELL, START_CELL, WALL_CELL, EMPTY_CELL
};

struct Cell
{
    enum cellType type;
    bool marked = false;
};

struct Maze
{
    std::vector<std::vector<Cell>> array;
    std::vector<Coord> path;
    bool finishPlaced = false;
    bool startPlaced = false;
    void resetMarked();
};