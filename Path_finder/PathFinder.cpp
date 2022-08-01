#include "PathFinder.h"


PathFinder::PathFinder()
{
}

void PathFinder::set_maze(Maze maze)
{
	maze_ = maze;
}

Maze PathFinder::maze()
{
	return maze_;
}

std::vector<GridSpace> PathFinder::solve_maze(GridSpace curent_pos, GridSpace previous_pos)
{
	return std::vector<GridSpace>();
}

std::vector<GridSpace> PathFinder::posible_moves_(GridSpace curent_pos)
{
	return std::vector<GridSpace>();
}
