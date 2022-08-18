#include "Button.h"
#include "../Consts.h"

Button::Button(sf::Vector2f position, int size, sf::Color color, std::string text, sf::Font& font)
{
	button_text_.setFont(font);
	button_text_.setString(text);
	button_text_.setCharacterSize(size);
	button_text_.setFillColor(color);
	auto center = button_text_.getLocalBounds().width / 2.f;
	button_text_.setOrigin({ center, button_text_.getGlobalBounds().top });
	button_text_.setPosition(position);
	button_color_ = color;
}

void Button::draw_to(sf::RenderWindow& window)
{
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
	if (button_text_.getGlobalBounds().contains({ float(mouse_pos.x), float(mouse_pos.y) }))
	{
		button_text_.setFillColor(sf::Color::White);
	}
	else
	{
		button_text_.setFillColor(button_color_);
	}
	window.draw(button_text_);
}

bool Button::is_pressed(sf::RenderWindow& window)
{
	sf::Vector2i mouse_pos = sf::Mouse::getPosition(window);
	return (button_text_.getGlobalBounds().contains({ float(mouse_pos.x), float(mouse_pos.y)})&&sf::Mouse::isButtonPressed(sf::Mouse::Left));
}


