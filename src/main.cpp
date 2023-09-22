#include <SFML/System.hpp>
#include "maze.hpp"
#include "graphics.hpp"
#include "input.hpp"
#include <iostream>
#include <string>




int main(int argc, char *argv[])
{
    if(argc < 3)
    {
        std::cerr << "Not enough args" << std::endl;
    }
    int x = std::stoi(argv[1]);
    int y = std::stoi(argv[2]);

    Graphics g(x,y);
    Maze m;
    Coord c;
    m.setSize(x,y);

    while(g.isOpen())
    {
        Input::process(m, c);
        g.process(m, c);
        sf::sleep(sf::milliseconds(50));
    }

}