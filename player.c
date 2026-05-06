#include "player.h"
#include <stdio.h>
#include <string.h>

void init_player(Character *p) {
    p->max_hp = 60;
    p->hp = p->max_hp;

    p->max_mp = 20;
    p->mp = p->max_mp;

    p->attack = 8;
    
    strcpy(p->name, "ゆうしゃ");

    p->stun = 0;
    p->poison = 0;

    p->level = 1;
    p->exp = 0;
    p->exp_to_next = 30;

    p->x = 2;
    p->y = 2;
}

void level_up(Character *p) {

    int old_max_hp = p->max_hp;
    int old_max_mp = p->max_mp;
    int old_attack = p->attack;

    p->level++;
    p->exp -= p->exp_to_next;
    p->exp_to_next += 10;

    p->max_hp += 10;
    p->max_mp += 5;
    p->attack += 2;

    p->hp = p->max_hp;
    p->mp = p->max_mp;

    p->exp_to_next += 10;

    printf("\n=== レベルアップ！ ===\n");
    printf("LV %d !\n", p->level);

    printf("HP: %d ~ %d (+%d)\n", old_max_hp, p->max_hp, p->max_hp - old_max_hp);
    printf("MP: %d ~ %d (+%d)\n", old_max_mp, p->max_mp, p->max_mp - old_max_mp);
    printf("ATK: %d ~ %d (+%d)\n", old_attack, p->attack, p->attack - old_attack);

    printf("HPとMP全回復！\n");
    printf("=====================\n\n");
}
