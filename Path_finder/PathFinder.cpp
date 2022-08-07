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
	std::vector<GridSpace> posible_moves = posible_moves_(curent_pos, previous_pos);
	if (posible_moves.size() == 0)
	{
		return std::vector<GridSpace>();
	}
	for (auto move : posible_moves)
	{
		if (maze_.maze_size()[0]-1 == move.grid_position()[0] && maze_.maze_size()[1] - 1 == move.grid_position()[1])
		{
			return{ move };
		}
		std::vector<GridSpace> solved = solve_maze(move, curent_pos);
		if (solved.begin() == solved.end())
		{
			return std::vector<GridSpace>();
		}
		else
		{
			solved.push_back(move);
			return solved;
		}
	}
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
		if ((pos_x == curent_x + 1 || pos_x == curent_x - 1) && pos_y == curent_y && previous_pos.grid_position()[0] != pos_x && previous_pos.grid_position()[1] != pos_y && position.space_state() == EMPTY_SPACE)
		{
			posible_moves.push_back(position);
		}
		else if ((pos_y == curent_y + 1 || pos_y == curent_y - 1) && pos_x == curent_x && previous_pos.grid_position()[0] != pos_x && previous_pos.grid_position()[1] != pos_y && position.space_state() == EMPTY_SPACE)
		{
			posible_moves.push_back(position);
		}
	}
	return posible_moves;
}
