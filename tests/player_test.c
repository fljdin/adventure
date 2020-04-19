#include <stdio.h>
#include <stdlib.h>
#include "engine/player.h"
#include "testing.h"

void player_is_created()
{
  Player player = CreatePlayer();
  assert_that(player.position >= 0);
}

int main()
{
  player_is_created();

  return 0;
}
