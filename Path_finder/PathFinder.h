#ifndef PathFinder_H
#define PathFinder_H
#include "GridSpace.h"
#include "Maze.h"


class PathFinder
{
private:
	std::vector<GridSpace> path_;
	Maze maze_;
	std::vector<GridSpace> posible_moves_(GridSpace curent_pos, GridSpace previous_pos);
public:
	PathFinder();
	void set_maze(Maze maze);
	Maze maze();
	std::vector<GridSpace> solve_maze(GridSpace curent_pos, GridSpace previous_pos);
};


#endif // !PathFinder_H

