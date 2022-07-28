#ifndef Maze_H
#define Maze_H
#include "GridSpace.h"
#include <string>


class Maze
{
private:
	std::vector<GridSpace> grid_;
	void create_row_from_string_(std::string row, int row_size, int row_num);
public:
	Maze();
	void generte_maze(std::vector<int> size);
	void maze_from_file(std::string file_name);
};


#endif // !Maze_H

