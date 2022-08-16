#ifndef Maze_H
#define Maze_H
#include "GridSpace.h"
#include <string>


class Maze
{
private:
	std::vector<GridSpace> grid_;
	std::vector<int> maze_size_;
	std::vector<GridSpace> path_;
	std::vector<std::vector<int> > start_stop = {{0}, {0}};
	void create_row_from_string_(std::string row, int row_size, int row_num);
	std::vector<GridSpace> generate_correct_path_(std::vector<int> size, std::vector<int> stop, std::vector<int> start);
	std::vector<std::vector<int> > check_available_directions_(std::vector<int> size, std::vector<int> curent_pos, std::vector<int> previous_pos);
	std::vector<std::vector<int> > check_if_space_taken_(std::vector<std::vector<int> > directions);
	bool check_if_space_is_path_(std::vector<int> position);
	void generate_grid_(std::vector<int> size);
public:
	std::vector<int> start();
	std::vector<int>stop();
	std::vector<int> maze_size();
	Maze();
	void generte_maze(std::vector<int> size, std::vector<int> stop = { -1, -1 }, std::vector<int> start = { 0, 0 });
	void maze_from_file(std::string file_name);
	std::vector<GridSpace> grid();
};


#endif // !Maze_H

