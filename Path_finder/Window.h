#ifndef Window_H
#define Window_H
#include "PathFinder.h"
#include <SFML/Graphics.hpp>


class Window
{
private:
	Maze maze_;
	PathFinder path_finder_;
	void draw_maze_(sf::RenderWindow& window);
public:
	Window();
	void open_window();
};


#endif // !Window_H

