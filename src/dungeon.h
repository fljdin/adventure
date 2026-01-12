#pragma once

enum room_type
{
    ROOM_EMPTY,
    ROOM_MONSTER,
    ROOM_CHEST,
    ROOM_SHOP,
    ROOM_BOSS
};

struct room
{
    int type;
    char *description;
};

struct dungeon
{
    unsigned current;
    unsigned total_rooms;
    struct room *rooms;
};

void dungeon_init(struct dungeon *d, unsigned const total, unsigned const rooms[]);
void dungeon_destroy(struct dungeon *d);
bool dungeon_open_door(struct dungeon *d);
struct room *dungeon_current_room(struct dungeon *d);
