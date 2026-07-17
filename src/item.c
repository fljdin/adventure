#include "item.h"

#define ITEM_DATA(name_, n_, w_, cat_, t_, ...) \
    [name_] = { .name = n_, .weight = w_, .category = cat_, .type = t_, __VA_ARGS__ },

static struct item const item_table[] =
{
    FOREACH_ITEM(ITEM_DATA)
};

struct item item_create(enum item_kind kind)
{
    return item_table[kind];
}
