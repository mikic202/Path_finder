#include "Maze.h"
#include <iostream>
#include "PathFinder.h"


int main()
{
	Maze maze;
	maze.generte_maze({2, 2});

	PathFinder path_f;
	path_f.set_maze(maze);
	std::vector<GridSpace> path_ = path_f.solve_maze(maze.grid()[0], GridSpace('e', {-1, -1}));
	for (auto i : path_)
	{
		std::cout<< i.grid_position()[0]<< " "<< i.grid_position()[1]<<"\n";
	}
}