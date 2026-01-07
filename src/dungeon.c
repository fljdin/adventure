#include <stdlib.h>
#include "dungeon.h"

void dungeon_init(dungeon_t *d, const size_t total, const room_type_t *rooms)
{
    if (!d || !total || !rooms) return;

    d->rooms = malloc(total * sizeof(room_t));
    if (!d->rooms) return;

    d->current = 0;
    d->total_rooms = total;

    for (size_t i = 0; i < total; i++)
    {
        d->rooms[i].type = rooms[i];
    }
}

void dungeon_destroy(dungeon_t *d)
{
    if (d->rooms) free(d->rooms);
    d->rooms = NULL;
    d->current = 0;
    d->total_rooms = 0;
}

bool dungeon_open_door(dungeon_t *d)
{
    if (!d || d->current + 1 == d->total_rooms) return false;
    d->current++;
    return true;
}

room_t* dungeon_current_room(dungeon_t *d)
{
    if (!d) return NULL;
    return &d->rooms[d->current];
}
