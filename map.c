#include <stdio.h>
#include <stdlib.h>
#include "battle.h"
#include "map.h"

#define WIDTH 10
#define HEIGHT 5

char map[HEIGHT][WIDTH + 1] = {
    "##########",
    "#..E.....#",
    "#.......E#",
    "#....E...#",
    "##########",
};

void draw_map(Character *p) {
    for (int y = 0; y < HEIGHT; y++) {
        for (int x = 0; x < WIDTH; x++) {

            if (x == p->x && y == p->y) {
                printf("@");
            } else {
                printf("%c", map[y][x]);
            }
        }
        printf("\n");
    }
}

int boss_spawned = 0;

int all_enemies_dead(Character enemies[], int count) {
    for (int i = 0; i < count; i++) {
        if (enemies[i].hp > 0 && enemies[i].type != DRAGON) {
            return 0;
        }
    }
    return 1;
}

void move_player(Character *p, Character enemies[]) {
    int new_x = p->x;
    int new_y = p->y;

    char input;
    printf("移動 w=↑ s=↓ a=← d=→: ");
    scanf(" %c", &input);

    if (input == 'w') new_y--;
    if (input == 's') new_y++;
    if (input == 'a') new_x--;
    if (input == 'd') new_x++;

    if (new_x < 0 || new_x >= WIDTH) return;
    if (new_y < 0 || new_y >= HEIGHT) return;

    if (map[new_y][new_x] == '#') return;

    if (!boss_spawned && all_enemies_dead(enemies, 3)) {
        printf("ドラゴンが現れた！\n");

        enemies[3].type = DRAGON;
        enemies[3].hp = 80;
        enemies[3].max_hp = 80;
        enemies[3].attack = 10;
        strcpy(enemies[3].name, "DRAGON");

        enemies[3].x = 5;
        enemies[3].y = 2;

        map[2][5] = 'D';

        boss_spawned = 1;
    }

for (int i = 0; i < 4; i++) {
    if (enemies[i].hp > 0 &&
        enemies[i].x == new_x &&
        enemies[i].y == new_y) {

        battle(p, &enemies[i]);

    if (map[new_y[]new_x] == 'E') {
        if (battle(p, enemies)) {
            printf("ゲームクリア！\n");
            exit(0);
        }
        map[new_y][new_x] = '.';
    }
}

p->x = new_x;
p->y = new_y;

int game_clear = 0;
    if (battle(p, enemies)) {
        game_clear = 1;
    }
    if (game_clear) return;
}
