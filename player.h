#ifndef PLAYER_H
#define PLAYER_H
#include <string.h>
#define SLIME 0
#define GOBLIN 1
#define ORC 2
#define DRAGON 3

typedef struct {
    int hp;
    int max_hp;

    int mp;
    int max_mp;

    int attack;
    char name[15];

    int stun;
    int poison;
    int burn;

    int level;
    int exp;
    int exp_to_next;

    int x;
    int y;

    int type;

} Character;

void init_player(Character *p);

void level_up(Character *p);

#endif
