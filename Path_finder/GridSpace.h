#ifndef GridSpace_H
#define GridSpace_H
#include <vector>


class GridSpace
{
private:
	char space_state_;
	std::vector<int> grid_position_;
	bool check_space_state(char space_state);
public:
	GridSpace(char space_state, std::vector<int> grid_position);
	std::vector<int> grid_position();
	char space_state();
	void set_space_state(char new_space_state);

};


#endif // !GridSpace_H
