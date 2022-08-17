#include "Window.h"


Window::Window()
{
	maze_ = Maze();
	maze_.generte_maze({ 10, 10 }, {7, 7}, {2, 1});
	path_finder_ = PathFinder();
}

void Window::open_window()
{
    sf::RenderWindow window_(sf::VideoMode(800, 800), "Pathfinder");
    path_finder_.set_maze(maze_);
    int i = 0;
    generate_maze_grid(window_);
    std::vector<GridSpace> path_ = path_finder_.solve_maze_sample();
    //for (auto space : path_)
    //{
    //    rects[i].setSize({ tile_size, tile_size });
    //    rects[i].setPosition({ float(space.grid_position()[0] * (tile_size + 4) + 1), float(space.grid_position()[1] * (tile_size + 4) + 1) });
    //    rects[i].setFillColor(sf::Color::Blue);
    //    window_.draw(rects[i]);
    //    i++;
    //}
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
	}
}

void Window::draw_maze_(sf::RenderWindow& window)
{
    for (auto space : rects_)
    {
        window.draw(space);
    }
}

void Window::generate_maze_grid(sf::RenderWindow& window)
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
}
