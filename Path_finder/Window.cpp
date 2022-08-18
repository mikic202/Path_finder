#include "Window.h"
#include <Windows.h>


Window::Window()
{
    if (!font_.loadFromFile(FONT_PATH))
    {
        throw(std::exception());
    }
	maze_ = Maze();
	maze_.generte_maze({ 30, 30 });
	path_finder_ = PathFinder();
}

void Window::open_window()
{
    sf::RenderWindow window_(sf::VideoMode(800, 800), "Pathfinder");
    path_finder_.set_maze(maze_);
    float tile_size = generate_maze_grid(window_);
    std::vector<int> options = start_menu(window_);
    std::vector<GridSpace> path_;
    if(options[2] == 2)
        path_ = path_finder_.solve_maze_sample();
    else if (options[2] == 1)
        path_ = path_finder_.solve_maze();
    int i = 0;
    buttons_.clear();
    window_.clear();
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
        if (i < path_.size())
        {
            update_path_(path_, i, tile_size);
            i++;
        }
	}
}

void Window::draw_maze_(sf::RenderWindow& window)
{
    window.clear();
    for (auto space : rects_)
    {
        window.draw(space);
    }
    window.display();
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
    Sleep(200);
}

std::vector<int> Window::start_menu(sf::RenderWindow& window)
{
    int winwow_w = window.getSize().x;

    buttons_.insert(std::pair<int, Button>(1, Button({ float(winwow_w) / 2, 300.f }, 50, sf::Color::Yellow, "Recursive", font_)));
    buttons_.insert(std::pair<int, Button>(2, Button({ float(winwow_w) / 2, 450.f }, 50, sf::Color::Yellow, "Sample", font_)));
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
                exit(1);
            }
        }
        for (auto button_pair : buttons_)
        {
            if (button_pair.second.is_pressed(window))
            {
                return { 0, 0, button_pair.first };
            }
        }
        window.clear();
        for (auto buttons : buttons_)
        {
            buttons.second.draw_to(window);
        }
        window.display();
    }
    return { 0, 0, 0 };
}
