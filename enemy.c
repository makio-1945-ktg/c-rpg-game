#include <string.h>
#include "enemy.h"

void init_enemies(Character enemies[]) {
    enemies[0].max_hp = 20;
    enemies[0].hp = 20;
    enemies[0].attack = 3;
    strcpy(enemies[0].name, "スライム");
    enemies[0].stun = 0;
    enemies[0].poison = 0;
    enemies[0].x = 3;
    enemies[0].y = 1;
    enemies[0].type = SLIME;

    enemies[1].max_hp = 25;
    enemies[1].hp = 25;
    enemies[1].attack = 4;
    strcpy(enemies[1].name, "ゴブリン");
    enemies[1].stun = 0;
    enemies[1].poison = 0;
    enemies[1].x = 5;
    enemies[1].y = 3;
    enemies[1].type = GOBLIN;

    enemies[2].max_hp = 40;
    enemies[2].hp = 40;
    enemies[2].attack = 5;
    strcpy(enemies[2].name, "オーク");
    enemies[2].stun = 0;
    enemies[2].poison = 0;
    enemies[2].x = 8;
    enemies[2].y = 2;
    enemies[2].type = ORC;
}
