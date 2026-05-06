#include <stdio.h>
#include <stdlib.h>
#include "battle.h"
#include "player.h"

void print_hp_bar(int hp, int max_hp) {
    int bar_length = 20;
    int filled = (hp * bar_length) / max_hp;

    printf("[");
    for (int i = 0; i < bar_length; i++) {
        if (i < filled) {
            printf("#");
        } else {
            printf(" ");
        }
    }
    printf("]");
}

int battle(Character *player, Character enemies[]) {

    printf("=== BATTLE START! ===\n");

    while (player->hp > 0) {

        int is_defending = 0;

        printf("\n=== PLAYER STATUS ===\n");
        printf("HP: %d ",player->hp);
        print_hp_bar(player->hp, player->max_hp);
        printf(" MP: %d\n", player->mp);
    if (player->poison > 0) {
        printf("【毒:%d】", player->poison);
    }
    if (player->burn > 0) {
        printf("【火傷:%d】", player->burn);
    }
        printf("Lv:%d EXP:%d/%d\n",
            player->level,
            player->exp,
            player->exp_to_next);

        printf("\n=== ENEMY ===\n");
        printf("%s HP:%d ", enemy->name, enemy->hp);
        print_hp_bar(enemy->hp, enemy->max_hp);
        printf("\n");

        if (player->stun == 1) {
            printf("プレイヤーはスタンした！\n");
            player->stun = 0;
        } else {

            int command;
            printf("1:攻撃 2:防御 3:回復 4:稲妻斬り\n");
            if (scanf("%d", &command) != 1) {
            printf("無効な入力！\n");
            return 0;
            }

            if (command == 1) {
                int damage = player->attack + (rand() % 5) - 2;
                if (damage < 1) damage = 1;

                if (rand() % 5 == 0) {
                    damage *= 2;
                    printf("クリティカル！\n");
                }

                enemy->hp -= damage;
                if (enemy->hp < 0) enemy->hp = 0;

                printf("%d ダメージ！\n", damage);

            } else if (command == 2) {
                is_defending = 1;
                printf("防御した！\n");
                continue;

            } else if (command == 3) {
                if (player->mp < 4) {
                    printf("MP不足！\n");
                    continue;
                }

                player->mp -= 4;
                player->hp += 15;
                if (player->hp > player->max_hp)
                    player->hp = player->max_hp;

                printf("回復した！\n");

            } else if (command == 4) {
                if (player->mp < 9) {
                    printf("MP不足！\n");
                    continue;
                }

                player->mp -= 9;

                int damage = player->attack * 2 + rand() % 5;
                enemy->hp -= damage;
                if (enemy->hp < 0) enemy->hp = 0;

                printf("稲妻斬りを放った！ %d ダメージ！\n", damage);
            }
        }

        if (enemy->hp <= 0) {
            printf("%s を倒した！\n", enemy->name);

            if (enemies[target].type == DRAGON) {
                printf(" ドラゴンを倒した！！ \n");
                return 1;
            }

            int exp_gain = 15;
            player->exp += exp_gain;

            while (player->exp >= player->exp_to_next) {
                level_up(player);
            }

            break;
        }

        if (enemy->stun == 1) {
            printf("%s は動けない！\n", enemy->name);
            enemy->stun = 0;
            continue;
        }

        if (enemy->type == SLIME) {

            if (rand() % 4 == 0) {
                int heal = 5;
                enemy->hp += heal;

                if (enemy->hp > enemy->max_hp)
                    enemy->hp = enemy->max_hp;

                printf("スライムは回復した！HP+%d\n", heal);
                continue;
            }

        } else if (enemy->type == GOBLIN) {

            if (rand() % 4 == 0) {
                if (player->poison == 0) {
                    player->poison = 3;
                    printf("ゴブリンは毒矢を放った！\n");
                }
            }

        } else if (enemy->type == ORC) {

            if (rand() % 3 == 0) {
                int damage = enemy->attack * 2;
                printf("オークは棍棒を振り回した！\n");

                player->hp -= damage;
                continue;
            }
        } else if (enemy->type == DRAGON) {

            if (rand() % 3 == 0) {
                int damage = enemy->attack + 5;
                printf("ドラゴンは炎を吐いた！\n");

                player->hp -= damage;
                player->burn = 3;

                printf("火傷状態になった！\n");
                continue;
            }

            if (enemy->hp < enemy->max_hp / 2 && rand() % 3 == 0) {
                int heal = 10;
                enemy->hp += heal;

                if (enemy->hp > enemy->max_hp)
                    enemy->hp = enemy->max_hp;

                printf("ドラゴンは目を閉じて瞑想した…傷が癒えていく！\n");
                continue;
            }
        }
            int damage = enemy->attack + (rand() % 5) - 2;
            if (damage < 1) damage = 1;

            if (is_defending) {
                damage /= 2;
                printf("防御で軽減！\n");
            }

            player->hp -= damage;
            printf("%sの攻撃！　%dダメージ\n", enemy->name, damage); 

            if (player->hp <= 0) {
                printf("あなたは倒れた…\n");
                break;
            }

            if (player->poison > 0) {
                player->hp -= 3;
                player->poison--;
                printf("毒のダメージ\n");
            }

            if (player->burn > 0) {
                int burn_damage = 4;
                player->hp -= burn_damage;
                player->burn--;

                printf("火傷ダメージ！%d\n", burn_damage);
            }

            if (player->mp < player->max_mp) {
                player->mp++;
            }
        }
    }
                
