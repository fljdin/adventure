#include <stdbool.h>

#define	MAX_PATHS 100
#define MAX_DIRECTIONS 3

enum direction {
	FRONT, RIGHT, BACK, LEFT
};

enum location {
	LOC_ROOM_1, LOC_ROOM_2, LOC_ROOM_3,
	LOC_CHAMBER
};

struct adventure {
	int player_location;
	int paths[MAX_PATHS][MAX_DIRECTIONS];
} adventure;

void advent_init(int start_location);
void advent_build_path(int from, int to);
void advent_build_path(int from, int to, int direction, bool *condition);
void advent_do_action(char *action);

int advent_player_location();
