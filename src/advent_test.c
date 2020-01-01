#include "testing.h"
#include "advent.h"

void test_player_movement() 
{
	advent_init(LOC_ROOM_1);
	advent_build_path(LOC_ROOM_1, LOC_CHAMBER);

	advent_do_action("move");
	assert_that(advent_player_location() == LOC_CHAMBER,
			"test_player_movement()");
}

int main()
{
	test_player_movement();

	return 0;
}
