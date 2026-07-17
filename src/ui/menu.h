#pragma once
#include <curses.h>

#define MENU_MAX 10

struct menu_item
{
    char const *label;
};

struct menu
{
    struct menu_item items[MENU_MAX];
    int count;
    int cursor;
};

void menu_init(struct menu *m);
int  menu_add(struct menu *m, char const *label);
int  menu_run(struct menu *m, WINDOW *win, int x, int y);
