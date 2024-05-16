#include "unity.h"
#include "Game.h"
#include "Player.h"
#include "Map.h"

void test_InitGame() {
    Player player = NewPlayer("p", 100);
    Room *room = NewMap(10);
    Game game = InitGame(&player, room);

    TEST_ASSERT_EQUAL(&player, game.player);
    TEST_ASSERT_EQUAL(room, game.room);
    TEST_ASSERT_EQUAL(1, game.level);
}

void test_OpenDoor() {
    Player player = NewPlayer("p", 100);
    Room *room = NewMap(10);
    Game game = InitGame(&player, room);

    OpenDoor(&game);

    TEST_ASSERT_EQUAL(2, game.level);
    TEST_ASSERT_EQUAL(room->door, game.room);
}
