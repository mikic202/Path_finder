#include "GridSpace.h"

GridSpace::GridSpace(char space_state, std::vector<int> grid_position)
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

char GridSpace::space_state()
{
	return space_state_;
}

void GridSpace::set_space_state(char new_space_state)
{
	if (check_space_state(new_space_state))
	{
		space_state_ = new_space_state;
	}
}
