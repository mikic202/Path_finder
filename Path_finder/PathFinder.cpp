#include "PathFinder.h"
#include <iostream>


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
			path_taken.pop_back();
			continue;
		}
	}
	if(possible_paths.size() == 0)
		return path_taken;
	return find_shortest_(possible_paths);
}

std::vector<GridSpace> PathFinder::solve_maze_sample()
{
	std::vector<GridSpace> adjacent_spaces;
	std::vector<GridSpace> previously_added;
	std::vector<GridSpace> to_add;
	std::vector<GridSpace> possible_spaces;

	std::vector<int> maze_size = maze_.maze_size();
	adjacent_spaces.push_back(maze_.grid()[0]);
	previously_added.push_back(maze_.grid()[0]);
	adjacent_spaces[0].set_space_state(0);
	previously_added[0].set_space_state(0);
	int away_from_start;
	while (!element_in_path_(maze_.grid().back(), adjacent_spaces))
	{
		for (auto space : previously_added)
		{
			possible_spaces = adjecment_spaces_(space, adjacent_spaces);
			for (auto adjecment_space : possible_spaces)
			{
				adjecment_space.set_space_state(space.space_state() + 1);
				to_add.push_back(adjecment_space);
				adjacent_spaces.push_back(adjecment_space);
			}
		}
		previously_added = to_add;
		to_add.clear();
	}
	return find_shortest_path_(adjacent_spaces);
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

std::vector<GridSpace> PathFinder::adjecment_spaces_(GridSpace space, std::vector<GridSpace> other_spaces)
{
	std::vector<GridSpace> adjecment_spaces;

	int curent_x = space.grid_position()[0];
	int curent_y = space.grid_position()[1];

	if (curent_x < maze_.maze_size()[0] - 1 && maze_.grid()[space.grid_position()[1] * maze_.maze_size()[0] + space.grid_position()[0] + 1].space_state() == EMPTY_SPACE && !element_in_path_(maze_.grid()[space.grid_position()[1] * maze_.maze_size()[0] + space.grid_position()[0] + 1], other_spaces))
	{
		adjecment_spaces.push_back(maze_.grid()[space.grid_position()[1] * maze_.maze_size()[0] + space.grid_position()[0] + 1]);
	}
	if (curent_x > 0 && maze_.grid()[space.grid_position()[1] * maze_.maze_size()[0] + space.grid_position()[0] - 1].space_state() == EMPTY_SPACE && !element_in_path_(maze_.grid()[space.grid_position()[1] * maze_.maze_size()[0] + space.grid_position()[0] - 1], other_spaces))
	{
		adjecment_spaces.push_back(maze_.grid()[space.grid_position()[1] * maze_.maze_size()[0] + space.grid_position()[0] - 1]);
	}
	if (curent_y < maze_.maze_size()[1] - 1 && maze_.grid()[(space.grid_position()[1]+1) * maze_.maze_size()[0] + space.grid_position()[0]].space_state() == EMPTY_SPACE && !element_in_path_(maze_.grid()[(space.grid_position()[1] + 1) * maze_.maze_size()[0] + space.grid_position()[0]], other_spaces))
	{
		adjecment_spaces.push_back(maze_.grid()[(space.grid_position()[1] + 1) * maze_.maze_size()[0] + space.grid_position()[0]]);
	}
	if (curent_y > 0 && maze_.grid()[(space.grid_position()[1] - 1) * maze_.maze_size()[0] + space.grid_position()[0]].space_state() == EMPTY_SPACE && !element_in_path_(maze_.grid()[(space.grid_position()[1] - 1) * maze_.maze_size()[0] + space.grid_position()[0]], other_spaces))
	{
		adjecment_spaces.push_back(maze_.grid()[(space.grid_position()[1] - 1) * maze_.maze_size()[0] + space.grid_position()[0]]);
	}
	return adjecment_spaces;
}

std::vector<GridSpace> PathFinder::find_shortest_path_(std::vector<GridSpace> numbered_spaces)
{
	std::vector<GridSpace> path_to_return_;
	GridSpace curent_space(numbered_spaces.back().space_state(), { maze_.maze_size()[0] - 1, maze_.maze_size()[1] - 1 });
	path_to_return_.push_back(curent_space);
	while (!element_in_path_(numbered_spaces[0], path_to_return_))
	{
		curent_space = find_lowest_number_space(curent_space, numbered_spaces);
		path_to_return_.push_back(curent_space);
	}

	return path_to_return_;
}

GridSpace PathFinder::find_lowest_number_space(GridSpace space, std::vector<GridSpace> other_spaces)
{
	GridSpace best_space = space;

	int curent_x = space.grid_position()[0];
	int curent_y = space.grid_position()[1];

	for (auto position : other_spaces)
	{
		int pos_x = position.grid_position()[0];
		int pos_y = position.grid_position()[1];
		if ((pos_x == curent_x + 1 || pos_x == curent_x - 1) && pos_y == curent_y && best_space.space_state() > position.space_state())
		{
			best_space = position;
		}
		else if ((pos_y == curent_y + 1 || pos_y == curent_y - 1) && pos_x == curent_x && best_space.space_state() > position.space_state())
		{
			best_space = position;
		}
	}
	return best_space;
}
