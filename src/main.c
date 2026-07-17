#include "ui/ui.h"
#include "ui/log.h"
#include "ui/bar.h"
#include "ui/menu.h"
#include "entity.h"
#include "combat.h"
#include "monster.h"
#include <curses.h>

static void refresh_screen(WINDOW *game, struct layout const *ly,
                           struct entity const *player,
                           struct entity const *monster,
                           struct log const *log)
{
    struct entity_view pv = { .name = player->name, .hp = player->health, .max = player->health_max };
    struct entity_view mv = { .name = monster->name, .hp = monster->health, .max = monster->health_max };

    werase(game);
    box(game, 0, 0);
    entity_view_draw(game, BOX_W, ly->hp_y, &pv, &mv);
    draw_separator(game, ly->sep1_y, BOX_W);
    log_draw(log, game, ly->log_y, BOX_W, LOG_LINES);
    draw_separator(game, ly->sep2_y, BOX_W);
    wnoutrefresh(game);
}

int main(void)
{
    ui_init();

    int term_rows, term_cols;
    getmaxyx(stdscr, term_rows, term_cols);

    struct layout ly = layout_make(term_rows, term_cols);
    WINDOW *game = ui_window(&ly);

    struct entity player;
    entity_init(&player, "Player", 30, 5, 10);

    struct entity monster;
    monster_spawn(&monster, MONSTER_GOBLIN);

    struct log log;
    log_init(&log);
    log_add(&log, "Bienvenue dans le donjon !");
    log_add(&log, "Un %s sauvage apparait !", monster.name);

    struct menu menu;
    menu_init(&menu);
    menu_add(&menu, "Attaquer");
    menu_add(&menu, "Inventaire");

    refresh_screen(game, &ly, &player, &monster, &log);
    doupdate();

    while (player.health > 0 && monster.health > 0)
    {
        int sel = menu_run(&menu, game, 2, ly.menu_y);

        if (sel == 0)
        {
            unsigned dmg = entity_attack(&player, &monster);
            log_add(&log, "Vous attaquez le %s (%u degats)", monster.name, dmg);

            if (monster.health > 0)
            {
                dmg = entity_attack(&monster, &player);
                log_add(&log, "Le %s vous attaque (%u degats)", monster.name, dmg);
            }
        }
        else if (sel == 1)
        {
            log_add(&log, "Rien a inventorier pour l'instant.");
        }
        else
        {
            break;
        }

        refresh_screen(game, &ly, &player, &monster, &log);
        doupdate();
    }

    if (monster.health == 0)
        log_add(&log, "Le %s est vaincu !", monster.name);
    else if (player.health == 0)
        log_add(&log, "Vous etes mort...");

    refresh_screen(game, &ly, &player, &monster, &log);
    doupdate();
    wgetch(game);

    entity_destroy(&player);
    entity_destroy(&monster);
    ui_teardown(game);
    return 0;
}
