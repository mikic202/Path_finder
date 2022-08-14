#include "GridSpace.h"
#include <typeinfo>

bool GridSpace::check_space_state(int space_state)
{
	if (space_state != EMPTY_SPACE && space_state != FULL_SPACE && typeid(space_state).name() != typeid(int).name())
	{
		throw(std::exception());
	}
	return true;
}

GridSpace::GridSpace(int space_state, std::vector<int> grid_position)
{
	if (check_space_state(space_state))
	{
		space_state_ = space_state;
	}
	grid_position_ = grid_position;
}

std::vector<int> GridSpace::grid_position()
{
	return grid_position_;
}

int GridSpace::space_state()
{
	return space_state_;
}

void GridSpace::set_space_state(int new_space_state)
{
	if (check_space_state(new_space_state))
	{
		space_state_ = new_space_state;
	}
}
