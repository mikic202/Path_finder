#ifndef Window_H
#define Window_H
#include "PathFinder.h"
#include <SFML/Graphics.hpp>


class Window
{
private:
	std::vector<sf::RectangleShape> rects_;
	Maze maze_;
	PathFinder path_finder_;
	void draw_maze_(sf::RenderWindow& window);
	float generate_maze_grid(sf::RenderWindow& window);
	void update_path_(std::vector<GridSpace> path, int index_num, float tile_size);
public:
	Window();
	void open_window();
};


#endif // !Window_H
