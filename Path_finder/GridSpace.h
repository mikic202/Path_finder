#ifndef GridSpace_H
#define GridSpace_H
#include <vector>
#include "const.h"


class GridSpace
{
private:
	int space_state_;
	std::vector<int> grid_position_;
	bool check_space_state(int space_state);
public:
	GridSpace(int space_state, std::vector<int> grid_position);
	std::vector<int> grid_position();
	int space_state();
	void set_space_state(int new_space_state);

};


#endif // !GridSpace_H
