#pragma once

typedef unsigned (*dice_func_t)(unsigned);

struct dice
{
    unsigned count;
    unsigned faces;
    int bonus;
};

struct dice_range
{
    unsigned low;
    unsigned high;
    int value;
};

unsigned dice_random(unsigned max);
unsigned dice_roll(struct dice const *d);
unsigned dice_roll_with_func(struct dice const *d, dice_func_t dice_func);
int dice_range_lookup(unsigned roll, struct dice_range const *ranges, unsigned count);
