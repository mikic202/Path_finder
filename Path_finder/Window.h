#ifndef Window_H
#define Window_H
#include "PathFinder.h"
#include <SFML/Graphics.hpp>
#include "Button.h"


class Window
{
private:
	sf::Font font_;
	std::vector<sf::RectangleShape> rects_;
	std::map<int, Button> buttons_;
	Maze maze_;
	PathFinder path_finder_;
	void draw_maze_(sf::RenderWindow& window);
	float generate_maze_grid(sf::RenderWindow& window);
	void update_path_(std::vector<GridSpace> path, int index_num, float tile_size);
	std::vector<int> start_menu(sf::RenderWindow& window);
	std::vector<int> size_options_(sf::RenderWindow& window, std::vector<int> size);
	void display_size_(sf::RenderWindow& window, std::vector<int> size);
	void draw_buttons_(sf::RenderWindow& window);
	std::vector<GridSpace> generate_path_(std::vector<int> options);
public:
	Window();
	void open_window();
};


#endif // !Window_H
