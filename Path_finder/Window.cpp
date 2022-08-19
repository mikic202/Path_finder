#include "Window.h"
#include <Windows.h>
#include <chrono>


Window::Window()
{
    if (!font_.loadFromFile(FONT_PATH))
    {
        throw(std::exception());
    }
	maze_ = Maze();
	path_finder_ = PathFinder();
}

void Window::open_window()
{
    sf::RenderWindow window_(sf::VideoMode(800, 800), "Pathfinder");
    std::vector<int> options = start_menu(window_);
    std::vector<GridSpace> path_ = generate_path_(options);
    
    float tile_size = generate_maze_grid(window_);
    int i = 0;
    window_.clear();
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
    std::chrono::time_point<std::chrono::steady_clock> last_change = std::chrono::high_resolution_clock::now();
    int winwow_w = window.getSize().x;
    std::vector<int> size = { 5, 5 };
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
        if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - last_change).count() > 80)
        {
            size = size_options_(window, size);
            last_change = std::chrono::high_resolution_clock::now();
        }
        for (auto button_pair : buttons_)
        {
            if (button_pair.second.is_pressed(window))
            {
                return { size[0], size[1], button_pair.first};
            }
        }
        window.clear();
        display_size_(window, size);
        draw_buttons_(window);
        window.display();
    }
    return { 0, 0, 0 };
}

std::vector<int> Window::size_options_(sf::RenderWindow& window, std::vector<int> size)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        size[1] += 1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && size[1] > 0)
    {
        size[1] -= 1;
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        size[0] += 1;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left) && size[0] > 0)
    {
        size[0] -= 1;
    }
    return size;
}

void Window::display_size_(sf::RenderWindow& window, std::vector<int> size)
{
    sf::Text size_x;
    size_x.setFont(font_);
    size_x.setString(std::to_string(size[0]));
    size_x.setCharacterSize(30);
    size_x.setFillColor(sf::Color::Yellow);
    auto center = size_x.getLocalBounds().width / 2.f;
    size_x.setOrigin({ center, size_x.getGlobalBounds().top });
    size_x.setPosition({ window.getSize().x / 3.f, 600.f});
    window.draw(size_x);

    sf::Text size_y;
    size_y.setFont(font_);
    size_y.setString(std::to_string(size[1]));
    size_y.setCharacterSize(30);
    size_y.setFillColor(sf::Color::Yellow);
    center = size_y.getLocalBounds().width / 2.f;
    size_y.setOrigin({ center, size_y.getGlobalBounds().top });
    size_y.setPosition({2* window.getSize().x / 3.f, 600.f });
    window.draw(size_y);

}

void Window::draw_buttons_(sf::RenderWindow& window)
{
    for (auto buttons : buttons_)
    {
        buttons.second.draw_to(window);
    }
}

std::vector<GridSpace> Window::generate_path_(std::vector<int> options)
{
    std::vector<GridSpace> path_;
    if (options[2] == 2)
    {
        maze_.generte_maze({ options[0], options[1] });
        path_finder_.set_maze(maze_);
        path_ = path_finder_.solve_maze_sample();
    }
    else if (options[2] == 1)
    {
        maze_.generte_maze({ options[0], options[1] });
        path_finder_.set_maze(maze_);
        path_ = path_finder_.solve_maze();
    }
    return path_;
}
