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

std::vector<GridSpace> PathFinder::posible_moves_(GridSpace curent_pos, GridSpace previous_pos)
{
	std::vector<GridSpace> posible_moves;

	int curent_x = curent_pos.grid_position()[0];
	int curent_y = curent_pos.grid_position()[1];

	for (auto position : maze_.grid())
	{
		int pos_x = position.grid_position()[0];
		int pos_y = position.grid_position()[1];
		if ((pos_x == curent_x + 1 || pos_x == curent_x - 1) && pos_y == curent_y && previous_pos.grid_position()[0] != pos_x && previous_pos.grid_position()[1] != pos_y)
		{
			posible_moves.push_back(position);
		}
		else if ((pos_y == curent_y + 1 || pos_y == curent_y - 1) && pos_x == curent_x && previous_pos.grid_position()[0] != pos_x && previous_pos.grid_position()[1] != pos_y)
		{
			posible_moves.push_back(position);
		}
	}
	return posible_moves;
}
