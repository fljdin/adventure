#pragma once
#include <curses.h>
#include "layout.h"

struct log
{
    char buf[LOG_BUF][256];
    int head;
    int count;
};

void log_init(struct log *l);
void log_add(struct log *l, char const *fmt, ...);
void log_draw(struct log const *l, WINDOW *win, int y, int w, int h);
