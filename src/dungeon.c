#include <stdlib.h>
#include "dungeon.h"

void dungeon_init(struct dungeon *d, unsigned const total, unsigned const rooms[])
{
    if (!d || !total || !rooms) return;

    d->rooms = malloc(total * sizeof(struct room));
    if (!d->rooms) return;

    d->current = 0;
    d->total_rooms = total;

    for (unsigned i = 0; i < total; i++)
    {
        d->rooms[i].type = rooms[i];
    }
}

void dungeon_destroy(struct dungeon *d)
{
    if (d->rooms) free(d->rooms);
    d->rooms = NULL;
    d->current = 0;
    d->total_rooms = 0;
}

bool dungeon_open_door(struct dungeon *d)
{
    if (!d || d->current + 1 == d->total_rooms) return false;
    d->current++;
    return true;
}

struct room *dungeon_current_room(struct dungeon *d)
{
    if (!d) return NULL;
    return &d->rooms[d->current];
}
