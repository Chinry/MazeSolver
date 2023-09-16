#include "../src/solve.hpp"
#include <CppUTest/TestHarness.h>

TEST_GROUP(SolveTests)
{

};

TEST(SolveTests, running_mazeFromInts____creates_a_maze )
{
    std::vector<std::vector<int>> nums = 
    {
        {1,1},
        {0,0},
        {2,3}
    };
    Maze m = mazeFromInts(nums);
    CHECK(m.array[0][0].type == WALL_CELL);
    CHECK(m.array[0][1].type == WALL_CELL);
    CHECK(m.array[1][0].type == EMPTY_CELL);
    CHECK(m.array[1][1].type == EMPTY_CELL);
    CHECK(m.array[2][0].type == START_CELL);
    CHECK(m.array[2][1].type == END_CELL);

}

TEST(SolveTests, getAdjacent____gets_adjacent_squares)
{
    std::vector<std::vector<int>> nums = 
    {
        {1,1,0},
        {0,0,0},
        {2,3,0}
    };
    Maze m = mazeFromInts(nums);
    Coord c;
    c.x = 1;
    c.y = 1;
    std::vector<Coord> adj = getAdjacent(m, c);
    CHECK(adj.size() == 3);
}

TEST(SolveTests, findCell____returns_correct_Coord)
{
    std::vector<std::vector<int>> nums = 
    {
        {1,1,0},
        {0,0,0},
        {2,3,0}
    };
    Maze m = mazeFromInts(nums);
    Coord c = findCell(m, START_CELL);
    CHECK(c.x == 0);
    CHECK(c.y == 2);
}
