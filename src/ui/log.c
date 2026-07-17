#include <stdarg.h>
#include <string.h>
#include "log.h"

void log_init(struct log *l)
{
    l->head = 0;
    l->count = 0;
}

void log_add(struct log *l, char const *fmt, ...)
{
    va_list ap;
    va_start(ap, fmt);
    vsnprintf(l->buf[l->head], sizeof l->buf[l->head], fmt, ap);
    va_end(ap);

    l->head = (l->head + 1) % LOG_BUF;
    if (l->count < LOG_BUF) l->count++;
}

void log_draw(struct log const *l, WINDOW *win, int y, int w, int h)
{
    int start = l->count < h ? 0
               : (l->head - h + LOG_BUF) % LOG_BUF;
    int n = l->count < h ? l->count : h;

    for (int i = 0; i < n; i++)
    {
        int idx = (start + i) % LOG_BUF;
        mvwprintw(win, y + i, 2, "%.*s", w - 3, l->buf[idx]);
    }
}
