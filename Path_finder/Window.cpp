#include "Window.h"
#include <Windows.h>


Window::Window()
{
	maze_ = Maze();
	maze_.generte_maze({ 30, 30 });
	path_finder_ = PathFinder();
}

void Window::open_window()
{
    sf::RenderWindow window_(sf::VideoMode(800, 800), "Pathfinder");
    path_finder_.set_maze(maze_);
    float tile_size = generate_maze_grid(window_);
    std::vector<GridSpace> path_ = path_finder_.solve_maze_sample();
    int i = path_.size()-1;
    window_.display();
	while (window_.isOpen())
	{
        sf::Event event;
        while (window_.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window_.close();
                exit(1);
            }
        }
        draw_maze_(window_);
        window_.display();
        if (i >= 0)
        {
            update_path_(path_, i, tile_size);
            i--;
        }
	}
}

void Window::draw_maze_(sf::RenderWindow& window)
{
    for (auto space : rects_)
    {
        window.draw(space);
    }
}

float Window::generate_maze_grid(sf::RenderWindow& window)
{
    float tile_size = std::min({ window.getSize().x/maze_.maze_size()[0] - 4, window.getSize().y/maze_.maze_size()[1] - 4});
    for (auto space : maze_.grid())
    {
        if (space.space_state() == FULL_SPACE)
        {
            rects_.push_back(sf::RectangleShape());
            rects_.back().setSize({ tile_size, tile_size });
            rects_.back().setPosition({ float(space.grid_position()[0] * (tile_size + 4) + 1), float(space.grid_position()[1] * (tile_size + 4) + 1) });
            rects_.back().setFillColor(sf::Color::Green);
        }
    }
    return tile_size;
}

void Window::update_path_(std::vector<GridSpace> path, int index_num, float tile_size)
{
    rects_.push_back(sf::RectangleShape());
    rects_.back().setSize({ tile_size, tile_size });
    rects_.back().setPosition({ float(path[index_num].grid_position()[0] * (tile_size + 4) + 1), float(path[index_num].grid_position()[1] * (tile_size + 4) + 1)});
    rects_.back().setFillColor(sf::Color::Blue);
    Sleep(300);
}
