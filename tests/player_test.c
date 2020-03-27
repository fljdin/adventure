#include <stdio.h>
#include "player.h"

void player_is_created()
{
  Player player = Player_create();
  assert_that(player != NULL);
  free(player);
}

int main()
{
  player_is_created();

  return 0;
}