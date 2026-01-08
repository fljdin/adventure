#pragma once

typedef unsigned int (*dice_func_t)(unsigned int);

typedef struct {
    unsigned int count;
    unsigned int faces;
    int bonus;
} dice_t;

unsigned int dice_random(unsigned int max);
unsigned int dice_roll(const dice_t *d);
unsigned int dice_roll_with_func(const dice_t *d, dice_func_t dice_func);
