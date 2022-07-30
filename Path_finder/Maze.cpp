#include "Maze.h"
#include <fstream>
#include <iostream>
#include <cstdlib>


Maze::Maze()
{
}

void Maze::generte_maze(std::vector<int> size)
{
	std::vector<GridSpace> path = generate_correct_path_(size);
	generate_grid_(size);
}

void Maze::maze_from_file(std::string file_name)
{
	grid_.clear();
	std::ifstream maze_file;
	std::string row_desc;
	maze_file.open(file_name);
	int row_num = 0;
	std::getline(maze_file, row_desc);
	int row_size = sizeof(row_desc) / sizeof(std::string);
	create_row_from_string_(row_desc, row_size, row_num);
	row_num++;
	while (std::getline(maze_file, row_desc))
	{
		create_row_from_string_(row_desc, row_size, row_num);
		row_num++;
	}
	maze_file.close();
}

std::vector<GridSpace> Maze::grid()
{
	return grid_;
}

void Maze::create_row_from_string_(std::string row, int row_size, int row_num)
{
	for (int i = 0; i < row_size; i++)
	{
		grid_.push_back(GridSpace(row[i], { i, row_num }));
	}
}

std::vector<std::vector<int>> Maze::check_available_directions_(std::vector<int> size, std::vector<int> curent_pos, std::vector<int> previous_pos)
{
	std::vector<std::vector<int>> available_direct;
	if (curent_pos[0] != 0 && curent_pos[0] != size[0] - 1)
	{
		if (curent_pos[0] < size[0] - 3 && curent_pos[0] > 2)
		{
			available_direct.push_back({ curent_pos[0] - 1, curent_pos[1] });
		}
		available_direct.push_back({ curent_pos[0] + 1, curent_pos[1] });
	}
	else if (curent_pos[0] == 0)
	{
		available_direct.push_back({ curent_pos[0] + 1, curent_pos[1] });
	}
	else
	{
		if (curent_pos[1] < size[1] - 3 && curent_pos[1] > 2)
			available_direct.push_back({ curent_pos[0] - 1, curent_pos[1] });
	}

	if (curent_pos[1] != 0 && curent_pos[1] != size[1] - 1)
	{
		if (curent_pos[0] < size[0] - 3 && curent_pos[0] > 2)
		{
			available_direct.push_back({ curent_pos[0], curent_pos[1] - 1 });
		}
		available_direct.push_back({ curent_pos[0], curent_pos[1] + 1 });
	}
	else if (curent_pos[1] == 0)
	{
		available_direct.push_back({ curent_pos[0], curent_pos[1] + 1 });
	}
	else
	{
		if (curent_pos[0] < size[0] - 3 && curent_pos[0] > 2)
			available_direct.push_back({ curent_pos[0], curent_pos[1] - 1 });
	}
	for (int i = 0; i< available_direct.size(); i++)
	{
		if (available_direct[i] == previous_pos)
		{
			available_direct.erase(available_direct.begin() + i);
			i--;
		}
	}
	available_direct = check_if_space_taken_(available_direct);
	return available_direct;
}

std::vector<std::vector<int>> Maze::check_if_space_taken_(std::vector<std::vector<int>> directions)
{
	for (int i = 0; i < directions.size(); i++)
	{
		for (auto space : path_)
		{
			if (directions[i] == space.grid_position())
			{
				directions.erase(directions.begin() + i);
				i--;
				break;
			}
		}
	}
	return directions;
}

bool Maze::check_if_space_is_path_(std::vector<int> position)
{
	for (auto space : path_)
	{
		if (position == space.grid_position())
		{
			return true;
		}
	}
	return false;
}

void Maze::generate_grid_(std::vector<int> size)
{
	srand(time(NULL));
	for (int i = 0; i < size[0]; i++)
	{
		for (int j = 0; j < size[1]; j++)
		{
			if (check_if_space_is_path_({ i, j }))
			{
				grid_.push_back(GridSpace(EMPTY_SPACE, { i, j }));
			}
			else
			{
				int random_val = rand() % 2;
				if (random_val == 0)
				{
					grid_.push_back(GridSpace(EMPTY_SPACE, { i, j }));
				}
				else
				{
					grid_.push_back(GridSpace(FULL_SPACE, { i, j }));
				}
			}
		}
	}
}

std::vector<GridSpace> Maze::generate_correct_path_(std::vector<int> size)
{
	srand(time(NULL));
	std::vector<int> less_size = { size[0] - 1, size[1] - 1 };
	path_.push_back(GridSpace(EMPTY_SPACE, { 0, 0 }));
	std::vector<std::vector<int>> available_direct = check_available_directions_(size, { 0, 0 }, { -1, -1 });
	path_.push_back(GridSpace(EMPTY_SPACE, available_direct[rand() % available_direct.size()]));
	int i = 1;
	while (path_[i].grid_position() != less_size)
	{
		available_direct = check_available_directions_(size, path_[i].grid_position(), path_[i-1].grid_position());
		path_.push_back(GridSpace(EMPTY_SPACE, available_direct[rand() % available_direct.size()]));
		i++;
	}
	return path_;
}
