#include "unity.h"
#include "dungeon.h"

struct dungeon dungeon;

void setUp(void)
{
    unsigned rooms[] = {ROOM_EMPTY, ROOM_MONSTER, ROOM_CHEST};
    dungeon_init(&dungeon, 3, rooms);
}

void tearDown(void)
{
    dungeon_destroy(&dungeon);
}

void test_dungeon_empty_room(void)
{
    struct dungeon d;
    dungeon_init(&d, 1, NULL);
}

void test_dungeon_total_rooms(void)
{
    TEST_ASSERT_EQUAL_INT(3, dungeon.total_rooms);
}

void test_dungeon_traverse_all_rooms(void)
{
    while (dungeon_open_door(&dungeon));
    struct room *room = dungeon_current_room(&dungeon);
    TEST_ASSERT_EQUAL_INT(ROOM_CHEST, room->type);
}
