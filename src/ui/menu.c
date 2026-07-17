#include "menu.h"

void menu_init(struct menu *m)
{
    m->count = 0;
    m->cursor = 0;
}

int menu_add(struct menu *m, char const *label)
{
    if (m->count >= MENU_MAX)
        return -1;
    m->items[m->count++].label = label;
    return 0;
}

int menu_run(struct menu *m, WINDOW *win, int x, int y)
{
    int key;

    for (;;)
    {
        for (int i = 0; i < m->count; i++)
        {
            mvwprintw(win, y + i, x,
                      i == m->cursor ? "> %s" : "  %s",
                      m->items[i].label);
        }

        wmove(win, y + m->cursor, x);
        wnoutrefresh(win);
        doupdate();

        key = wgetch(win);

        switch (key)
        {
        case KEY_UP:
            if (m->cursor > 0) m->cursor--;
            break;
        case KEY_DOWN:
            if (m->cursor < m->count - 1) m->cursor++;
            break;
        case '\n':
            return m->cursor;
        case 27:
            return -1;
        }
    }
}
