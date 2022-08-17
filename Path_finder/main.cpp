#include "Maze.h"
#include <iostream>
#include "PathFinder.h"
#include "Window.h"
#include <chrono>


int main()
{
	//Maze maze;
	//maze.generte_maze({4, 4}, {2, 2}, {1, 1});
	//std::cout << "a";
	//PathFinder path_f;
	//path_f.set_maze(maze);
	//auto start = std::chrono::steady_clock::now();
	//std::vector<GridSpace> path_ = path_f.solve_maze_sample();
	//auto end = std::chrono::steady_clock::now();
	//std::cout << "Elapsed time in milliseconds: "
	//	<< std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count()
	//	<< " ms" << std::endl;
	//for (auto i : path_)
	//{
	//	std::cout<< i.grid_position()[0]<< " "<< i.grid_position()[1]<<"\n";
	//}

	Window win;
	win.open_window();
}