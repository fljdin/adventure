#pragma once

typedef unsigned (*dice_func_t)(unsigned);

typedef struct {
    unsigned count;
    unsigned faces;
    int bonus;
} dice_t;

unsigned dice_random(unsigned max);
unsigned dice_roll(const dice_t *d);
unsigned dice_roll_with_func(const dice_t *d, dice_func_t dice_func);
