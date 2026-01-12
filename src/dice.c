#include <stdlib.h>
#include "dice.h"

unsigned dice_random(unsigned max)
{
    if (max == 0) return 0;
    return (rand() % max) + 1;
}

unsigned dice_roll(dice_t const *d)
{
    return dice_roll_with_func(d, dice_random);
}

unsigned dice_roll_with_func(dice_t const *d, dice_func_t dice_func)
{
    if (!d || !dice_func) return 0;

    int total = d->bonus;
    for (unsigned i = 0; i < d->count; i++)
    {
        total += dice_func(d->faces);
    }
    return total;
}
