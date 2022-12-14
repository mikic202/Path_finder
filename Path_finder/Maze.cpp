#include "Maze.h"
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <string>


std::vector<int> Maze::maze_size()
{
	return maze_size_;
}

Maze::Maze(int maze_fill)
{
	maze_fil_proc_ = maze_fill;
}

void Maze::generte_maze(std::vector<int> size, std::vector<int> stop,  std::vector<int> start)
{
	if (stop[0] == -1 && stop[1] == -1)
		stop = { size[0] - 1, size[1] - 1 };
	start_stop[0] = start;
	start_stop[1] = stop;
	maze_size_ = size;
	std::vector<GridSpace> path = generate_correct_path_(size, stop, start);
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
	int row_size = row_desc.size();
	create_row_from_string_(row_desc, row_size, row_num);
	row_num++;
	while (std::getline(maze_file, row_desc))
	{
		create_row_from_string_(row_desc, row_size, row_num);
		row_num++;
	}
	maze_size_ = { row_size, row_num };
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
		grid_.push_back(GridSpace((int)row[i]-48, { i, row_num }));
	}
}

std::vector<std::vector<int>> Maze::check_available_directions_(std::vector<int> size, std::vector<int> curent_pos, std::vector<int> previous_pos)
{
	std::vector<std::vector<int>> available_direct;
	int curent_x = curent_pos[0];
	int curent_y = curent_pos[1];
	if (curent_x < size[0] - 1)
	{
		available_direct.push_back({ curent_x + 1, curent_y});
	}
	if (curent_x > 0 )
	{
		available_direct.push_back({ curent_x - 1, curent_y });
	}
	if (curent_y < size[1] - 1)
	{
		available_direct.push_back({ curent_x, curent_y + 1 });
	}
	if (curent_y > 0)
	{
		available_direct.push_back({ curent_x, curent_y -1});
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
	for (int i = 0; i < size[1]; i++)
	{
		for (int j = 0; j < size[0]; j++)
		{
			if (check_if_space_is_path_({ j, i }))
			{
				grid_.push_back(GridSpace(EMPTY_SPACE, { j, i }));
			}
			else
			{
				int random_val = rand() % 100;
				if (random_val < maze_fil_proc_ )
				{
					grid_.push_back(GridSpace(EMPTY_SPACE, { j, i }));
				}
				else
				{
					grid_.push_back(GridSpace(FULL_SPACE, { j, i }));
				}
			}
		}
	}
}

std::vector<int> Maze::start()
{
	return start_stop[0];
}

std::vector<int> Maze::stop()
{
	return start_stop[1];
}

std::vector<GridSpace> Maze::generate_correct_path_(std::vector<int> size, std::vector<int> stop, std::vector<int> start)
{
	srand(time(NULL));
	path_.push_back(GridSpace(EMPTY_SPACE, start));
	std::vector<std::vector<int>> available_direct = check_available_directions_(size, start, { -1, -1 });
	path_.push_back(GridSpace(EMPTY_SPACE, available_direct[rand() % available_direct.size()]));
	int i = 1;
	while (path_[i].grid_position() != stop)
	{
		available_direct = check_available_directions_(size, path_[i].grid_position(), path_[i-1].grid_position());
		if (available_direct.size() == 0)
		{
			path_.clear();
			path_.push_back(GridSpace(EMPTY_SPACE, { 0, 0 }));
			std::vector<std::vector<int>> available_direct = check_available_directions_(size, start, { -1, -1 });
			path_.push_back(GridSpace(EMPTY_SPACE, available_direct[rand() % available_direct.size()]));
			i = 1;
			continue;
		}
		path_.push_back(GridSpace(EMPTY_SPACE, available_direct[rand() % available_direct.size()]));
		i++;
	}
	return path_;
}
