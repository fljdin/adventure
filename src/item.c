#include <string.h>
#include "item.h"

struct item_def
{
    char const *name;
    unsigned weight;
    enum item_type type;
    struct dice damage;
    unsigned armor_value;
};

#define ITEM_DATA(name_, n_, w_, t_, dc_, df_, db_, av_) \
    [name_] = { .name = n_, .weight = w_, .type = t_, \
                .damage = { .count = dc_, .faces = df_, .bonus = db_ }, \
                .armor_value = av_ },

static struct item_def const item_table[] =
{
    FOREACH_ITEM(ITEM_DATA)
};

struct item item_create(enum item_kind kind)
{
    struct item_def const *def = &item_table[kind];
    struct item it;
    strcpy(it.name, def->name);
    it.weight = def->weight;
    it.type = def->type;

    if (def->type == ITEM_WEAPON)
        it.damage = def->damage;
    else if (def->type == ITEM_ARMOR)
        it.value = def->armor_value;

    return it;
}
