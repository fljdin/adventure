#include <string.h>
#include "bar.h"
#include "layout.h"

void entity_view_draw(WINDOW *win, int w, int y,
                      struct entity_view const *player,
                      struct entity_view const *monster)
{
    char pbar[BAR_W + 1], mbar[BAR_W + 1];

    unsigned pf = (player->hp * BAR_W + player->max - 1) / player->max;
    unsigned mf = (monster->hp * BAR_W + monster->max - 1) / monster->max;
    if (pf > BAR_W) pf = BAR_W;
    if (mf > BAR_W) mf = BAR_W;

    for (unsigned i = 0; i < BAR_W; i++)
    {
        pbar[i] = i < pf ? '#' : '.';
        mbar[i] = i < mf ? '#' : '.';
    }
    pbar[BAR_W] = '\0';
    mbar[BAR_W] = '\0';

    char pline[64], mline[64];
    snprintf(pline, sizeof pline, " %s %3u/%u %s",
             player->name, player->hp, player->max, pbar);
    snprintf(mline, sizeof mline, " %s %3u/%u %s",
             monster->name, monster->hp, monster->max, mbar);

    if ((int)strlen(pline) + 2 + (int)strlen(mline) >= w - 2)
    {
        mvwprintw(win, y,     1, "%s", pline);
        mvwprintw(win, y + 1, 1, "%s", mline);
    }
    else
    {
        mvwprintw(win, y, 1, "%s", pline);
        mvwprintw(win, y, w - 2 - (int)strlen(mline), "%s", mline);
    }
}
