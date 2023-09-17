#include "../src/solve.hpp"
#include <iostream>
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

TEST(SolveTests, solveSimplePath)
{
    std::vector<std::vector<int>> nums = 
    {
        {2,0,3}
    };
    Maze m = mazeFromInts(nums);

    CHECK(solve(m));
    CHECK(m.array[0][0].marked);
    CHECK(m.array[0][1].marked);
    CHECK(m.array[0][2].marked);
}

TEST(SolveTests, solveComplexPath)
{
    std::vector<std::vector<int>> nums = 
    {
        {1,1,1,1,3},
        {1,1,1,1,0},
        {1,0,0,0,0},
        {1,0,1,1,1},
        {2,0,1,1,1}
    };
    Maze m = mazeFromInts(nums);

    CHECK(solve(m));
    CHECK(m.array[4][0].marked);
    CHECK(m.array[4][1].marked);
    CHECK(m.array[3][1].marked);
    CHECK(m.array[2][1].marked);
    CHECK(m.array[2][2].marked);
    CHECK(m.array[2][3].marked);
    CHECK(m.array[2][4].marked);
    CHECK(m.array[1][4].marked);
    CHECK(m.array[0][4].marked);
    CHECK(m.path.size() == 9);
}

TEST(SolveTests, solveDeadEndPath)
{
    std::vector<std::vector<int>> nums = 
    {
        {1,0,1,1,3},
        {1,0,1,1,0},
        {1,0,0,0,0},
        {1,0,1,1,1},
        {2,0,1,1,1}
    };
    Maze m = mazeFromInts(nums);

    CHECK(solve(m));
    CHECK(m.array[4][0].marked);
    CHECK(m.array[4][1].marked);
    CHECK(m.array[3][1].marked);
    CHECK(m.array[2][1].marked);
    CHECK(m.array[2][2].marked);
    CHECK(m.array[2][3].marked);
    CHECK(m.array[2][4].marked);
    CHECK(m.array[1][4].marked);
    CHECK(m.array[0][4].marked);
    CHECK(m.path.size() == 9);
}