#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "const.h"
#include "GridSpace.h"
#include "Maze.h"


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


TEST_CASE("test Maze class")
{
	SECTION("test initialization")
	{
		REQUIRE_NOTHROW(Maze());
	}

	SECTION("generate maze test")
	{
		Maze maze;
		maze.generte_maze({ 8, 8 });
		REQUIRE(maze.grid().size() == 8 * 8);
	}
}