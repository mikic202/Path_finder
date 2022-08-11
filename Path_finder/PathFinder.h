#ifndef PathFinder_H
#define PathFinder_H
#include "GridSpace.h"
#include "Maze.h"


class PathFinder
{
private:
	std::vector<GridSpace> path_;
	Maze maze_;
	std::vector<GridSpace> posible_moves_(std::vector<GridSpace> path_taken);
	bool element_in_path_(GridSpace element, std::vector<GridSpace> path_taken);
	std::vector<GridSpace> find_shortest_(std::vector<std::vector<GridSpace> >);
public:
	PathFinder();
	void set_maze(Maze maze);
	Maze maze();
	std::vector<GridSpace> solve_maze(std::vector<GridSpace> path_taken);
};


#endif // !PathFinder_H

