#include <stdlib.h>
#include "Map.h"

Room* NewRoom(void)
{
    Room *room = malloc(sizeof(Room));
    room->description = malloc(100);
    room->door = NULL;

    return room;
}

Room* NewMap(int size)
{
    Room *room = NewRoom();
    Room *start = room;

    for (int i = 0; i < size - 1; i++)
    {
        room->door = NewRoom();
        room = room->door;
    }

    return start;
}
