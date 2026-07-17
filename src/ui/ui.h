#pragma once
#include <curses.h>
#include "layout.h"

void ui_init(void);
WINDOW *ui_window(struct layout const *l);
void ui_teardown(WINDOW *game);
void draw_separator(WINDOW *win, int y, int w);
