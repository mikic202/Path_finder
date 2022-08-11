#include "Window.h"


Window::Window()
{
	maze_ = Maze();
	maze_.generte_maze({ 8, 8 });
	path_finder_ = PathFinder();
}

void Window::open_window()
{
    sf::RenderWindow window_(sf::VideoMode(825, 825), "Bomberman");
    path_finder_.set_maze(maze_);
    int i = 0;
    sf::RectangleShape rects[85];
    for (auto space : maze_.grid())
    {
        if (space.space_state() == FULL_SPACE)
        {
            rects[i].setSize({50, 50});
            rects[i].setPosition({ float(space.grid_position()[0] * 50), float(space.grid_position()[1] * 50) });
            rects[i].setFillColor(sf::Color::Green);
            window_.draw(rects[i]);
            i++;
        }
    }
    std::vector<GridSpace> path_ = path_finder_.solve_maze({ maze_.grid()[0] });
    for (auto space : path_)
    {
        rects[i].setSize({ 50, 50 });
        rects[i].setPosition({ float(space.grid_position()[0] * 50), float(space.grid_position()[1] * 50) });
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
