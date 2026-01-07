#pragma once
#include <stddef.h>
#include <stdbool.h>

typedef enum {
    ROOM_EMPTY,
    ROOM_MONSTER,
    ROOM_CHEST,
    ROOM_SHOP,
    ROOM_BOSS
} room_type_t;

typedef struct {
    int type;
    char* description;
} room_t;

typedef struct {
    size_t current;
    size_t total_rooms;
    room_t *rooms;
} dungeon_t;

void dungeon_init(dungeon_t *d, const size_t total, const room_type_t *rooms);
void dungeon_destroy(dungeon_t *d);
bool dungeon_open_door(dungeon_t *d);
room_t* dungeon_current_room(dungeon_t *d);
