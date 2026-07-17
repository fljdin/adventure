#include "ui/ui.h"
#include "ui/log.h"
#include "ui/bar.h"
#include "ui/menu.h"
#include <curses.h>

int main(void)
{
    ui_init();

    int term_rows, term_cols;
    getmaxyx(stdscr, term_rows, term_cols);

    struct layout ly = layout_make(term_rows, term_cols);

    WINDOW *game = ui_window(&ly);

    struct log log;
    log_init(&log);
    log_add(&log, "Bienvenue dans le donjon !");

    struct entity_view player = { .name = "Player", .hp = 20, .max = 30 };
    struct entity_view goblin  = { .name = "Gobelin", .hp = 5, .max = 10 };

    werase(game);
    box(game, 0, 0);
    entity_view_draw(game, BOX_W, ly.hp_y, &player, &goblin);
    draw_separator(game, ly.sep1_y, BOX_W);
    log_draw(&log, game, ly.log_y, BOX_W, LOG_LINES);
    draw_separator(game, ly.sep2_y, BOX_W);
    struct menu menu;
    menu_init(&menu);
    menu_add(&menu, "Attaquer");
    menu_add(&menu, "Inventaire");

    wnoutrefresh(game);
    doupdate();

    int sel;
    do
    {
        sel = menu_run(&menu, game, 2, ly.menu_y);
        if (sel >= 0)
        {
            log_add(&log, "%s", menu.items[sel].label);
            log_draw(&log, game, ly.log_y, BOX_W, LOG_LINES);
            wnoutrefresh(game);
            doupdate();
        }
    } while (sel >= 0);

    ui_teardown(game);
    return 0;
}
