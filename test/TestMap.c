#include "unity.h"
#include "Map.h"

void test_NewMapWithOneRoom(void)
{
    Room *room = NewMap(1);

    // the map should have only one room
    TEST_ASSERT_NOT_NULL(room);
    TEST_ASSERT_NULL(room->door);
}

void test_NewMap(void)
{
    int size = 10;
    int doorCount = 0;
    Room *room = NewMap(size);

    // pass through all doors
    while (room->door != NULL)
    {
        room = room->door;
        doorCount++;
    }

    // the last room should have no door
    TEST_ASSERT_NULL(room->door);
    TEST_ASSERT_EQUAL(size - 1, doorCount);
}

void test_NewRoom(void)
{
    Room *room = NewRoom();

    // a room should have a description
    TEST_ASSERT_NOT_NULL(room->description);
    TEST_ASSERT_NULL(room->door);
}
