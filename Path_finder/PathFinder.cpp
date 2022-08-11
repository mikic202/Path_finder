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

std::vector<GridSpace> PathFinder::solve_maze(std::vector<GridSpace> path_taken)
{
	//need to refactor the method to make use of path taken vector
	std::vector<GridSpace> posible_moves = posible_moves_(path_taken);
	int path_spaces = path_taken.size();
	if (posible_moves.size() == 0)
	{
		return path_taken;
	}
	for (auto move : posible_moves)
	{
		if (maze_.maze_size()[0]-1 == move.grid_position()[0] && maze_.maze_size()[1] - 1 == move.grid_position()[1])
		{
			path_taken.push_back(move);
			return path_taken;
		}
		path_taken.push_back(move);
		std::vector<GridSpace> solved = solve_maze(path_taken);
		if (solved.size() <= path_spaces + 1)
		{
			path_taken.pop_back();
			continue;
		}
		else
		{
			return solved;
		}
	}
	return path_taken;
}

std::vector<GridSpace> PathFinder::posible_moves_(std::vector<GridSpace> path_taken)
{
	std::vector<GridSpace> posible_moves;

	int curent_x = path_taken.back().grid_position()[0];
	int curent_y = path_taken.back().grid_position()[1];

	for (auto position : maze_.grid())
	{
		int pos_x = position.grid_position()[0];
		int pos_y = position.grid_position()[1];
		if ((pos_x == curent_x + 1 || pos_x == curent_x - 1) && pos_y == curent_y && !element_in_path_(position, path_taken) && position.space_state() == EMPTY_SPACE)
		{
			posible_moves.push_back(position);
		}
		else if ((pos_y == curent_y + 1 || pos_y == curent_y - 1) && pos_x == curent_x && !element_in_path_(position, path_taken) && position.space_state() == EMPTY_SPACE)
		{
			posible_moves.push_back(position);
		}
	}
	return posible_moves;
}

bool PathFinder::element_in_path_(GridSpace element, std::vector<GridSpace> path_taken)
{
	for (auto space : path_taken)
	{
		if (element.grid_position() == space.grid_position())
		{
			return true;
		}
	}
	return false;
}
