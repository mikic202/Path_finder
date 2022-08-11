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
	// need to fix small errors
	std::vector<GridSpace> posible_moves = posible_moves_(path_taken);
	std::vector<std::vector<GridSpace> > possible_paths;
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
			std::vector<GridSpace> temp_path = path_taken;
			possible_paths.push_back(temp_path);
			path_taken.pop_back();
			continue;
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
			std::vector<GridSpace> temp_path = solved;
			possible_paths.push_back(temp_path);
			continue;
		}
	}
	if(possible_paths.size() == 0)
		return path_taken;
	return find_shortest_(possible_paths);
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

std::vector<GridSpace> PathFinder::find_shortest_(std::vector<std::vector<GridSpace>> paths)
{
	std::vector<GridSpace> shortest_path;
	shortest_path = paths[0];
	for (auto path : paths)
	{
		if (path.size() < shortest_path.size())
		{
			shortest_path = path;
		}
	}
	return shortest_path;
}
