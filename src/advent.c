#include "advent.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

static struct adventure advent;

void advent_init(int start_location)
{
	advent.player_location = start_location;
}

void advent_build_path(int from, int to)
{
	advent.paths[from][FRONT] = to;
}

void advent_build_path(int from, int to, int direction, bool *condition)
{

}

void advent_do_action(char *action)
{
	if (strcmp(action, "move") == 0) {
		advent.player_location = 
			advent.paths[advent.player_location][FRONT];
	}
}

int advent_player_location()
{
	return advent.player_location;
}
