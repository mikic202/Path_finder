#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "const.h"
#include "GridSpace.h"


TEST_CASE("test GridSpace class")
{
	SECTION("test initialization")
	{
		GridSpace space(EMPTY_SPACE, { 1, 2 });

		REQUIRE(space.space_state() == EMPTY_SPACE);
		REQUIRE(space.grid_position()[0] == 1);
	}

	SECTION("setters tests")
	{
		GridSpace space(EMPTY_SPACE, { 1, 2 });

		space.set_space_state(FULL_SPACE);
		REQUIRE(space.space_state() == FULL_SPACE);
	}
}