#include "testing.h"
#include "advent.h"
#include <stdbool.h>

void test_player_movement() 
{
	advent_init(LOC_ROOM_1);
	advent_build_path(LOC_ROOM_1, LOC_CHAMBER);

	advent_do_action("move");
	assert_that(advent_player_location() == LOC_CHAMBER,
		"test_player_movement()");
}

void test_action_requirement()
{
	advent_init(LOC_ROOM_1);

	bool opened = false;
	advent_build_path(LOC_ROOM_1, LOC_ROOM_2, RIGHT, &opened);

	advent_do_action("open door");
	advent_do_action("move right");
	assert_that(advent_player_location() == LOC_CHAMBER,
		"test_action_requirement()");
}

int main()
{
	test_player_movement();
	test_action_requirement();

	return 0;
}
