#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "player.h"
#include "enemy.h"
#include "battle.h"
#include "map.h"

int main() {
    srand(time(NULL));

    Character player;
    Character enemies[3];

    init_player(&player);
    init_enemies(enemies);

    while (1) {
        draw_map(&player, enemies);
        move_player(&player, enemies);
    }

    return 0;
}
