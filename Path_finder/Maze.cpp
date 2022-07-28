#include "Maze.h"
#include <fstream>


Maze::Maze()
{
}

void Maze::generte_maze(std::vector<int> size)
{
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

void Maze::create_row_from_string_(std::string row, int row_size, int row_num)
{
	for (int i = 0; i < row_size; i++)
	{
		grid_.push_back(GridSpace(row[i], { i, row_num }));
	}
}