#include "Window.h"


Window::Window()
{
	maze_ = Maze();
	maze_.generte_maze({ 40, 40 });
	path_finder_ = PathFinder();
}

void Window::open_window()
{
    sf::RenderWindow window_(sf::VideoMode(1000, 1000), "Bomberman");
    path_finder_.set_maze(maze_);
    int i = 0;
    sf::RectangleShape rects[825];
    float tile_size = 20;
    for (auto space : maze_.grid())
    {
        if (space.space_state() == FULL_SPACE)
        {
            rects[i].setSize({ tile_size, tile_size });
            rects[i].setPosition({ float(space.grid_position()[0] * (tile_size + 4) + 1), float(space.grid_position()[1] * (tile_size + 4) + 1) });
            rects[i].setFillColor(sf::Color::Green);
            window_.draw(rects[i]);
            i++;
        }
    }
    std::vector<GridSpace> path_ = path_finder_.solve_maze_sample();
    for (auto space : path_)
    {
        rects[i].setSize({ tile_size, tile_size });
        rects[i].setPosition({ float(space.grid_position()[0] * (tile_size + 4) + 1), float(space.grid_position()[1] * (tile_size + 4) + 1) });
        rects[i].setFillColor(sf::Color::Blue);
        window_.draw(rects[i]);
        i++;
    }
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
        //draw_maze_(window_);
	}
}

void Window::draw_maze_(sf::RenderWindow& window)
{
    for (auto space : maze_.grid())
    {
        if (space.space_state() == FULL_SPACE)
        {
            sf::RectangleShape rect;
            rect.setSize({ 1, 1 });
            rect.setPosition({ float(space.grid_position()[0] * 30), float(space.grid_position()[1] * 30) });
            rect.setFillColor(sf::Color::Black);
            window.draw(rect);
        }
    }
}
