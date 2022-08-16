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
	std::vector<GridSpace> adjecment_spaces_(GridSpace space, std::vector<GridSpace> other_spaces);
	std::vector<GridSpace> find_shortest_path_(std::vector<GridSpace> numbered_spaces);
	GridSpace find_lowest_number_space(GridSpace space, std::vector<GridSpace> other_spaces);
public:
	PathFinder();
	void set_maze(Maze maze);
	Maze maze();
	std::vector<GridSpace> solve_maze(std::vector<GridSpace> path_taken = {GridSpace(EMPTY_SPACE, {-1, -1})});
	std::vector<GridSpace> solve_maze_sample();
};


#endif // !PathFinder_H

