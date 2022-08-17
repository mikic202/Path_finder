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
	void generate_maze_grid(sf::RenderWindow& window);
public:
	Window();
	void open_window();
};


#endif // !Window_H
