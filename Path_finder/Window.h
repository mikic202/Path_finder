#ifndef Window_H
#define Window_H
#include "PathFinder.h"


class Window
{
private:
	Maze maze_;
	PathFinder path_finder_;
	sf::RenderWindow window_;
public:
	Window();
	void open_window();
};


#endif // !Window_H

