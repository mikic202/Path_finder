#ifndef Maze_H
#define Maze_H
#include "GridSpace.h"
#include <string>


class Maze
{
private:
	std::vector<GridSpace> path_;
	std::vector<GridSpace> grid_;
	void create_row_from_string_(std::string row, int row_size, int row_num);
	std::vector<GridSpace> generate_correct_path_(std::vector<int> size);
	std::vector<std::vector<int> > check_available_directions_(std::vector<int> size, std::vector<int> curent_pos, std::vector<int> previous_pos);
	std::vector<std::vector<int> > check_if_space_taken_(std::vector<std::vector<int> > directions);
public:
	Maze();
	void generte_maze(std::vector<int> size);
	void maze_from_file(std::string file_name);
};


#endif // !Maze_H

