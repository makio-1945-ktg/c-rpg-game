#include <stdio.h>
#include <stdlib.h>
#include "battle.h"
#include "player.h"
#include "enemy.h"

void print_hp_bar(int hp, int max_hp) {
    int bar_length = 20;
    int filled = (hp * bar_length) / max_hp;

    printf("[");
    for (int i = 0; i < bar_length; i++) {
        if (i < filled) printf("#");
        else printf(" ");
    }
    printf("]");
}

int battle(Character *player, Character *enemy) {

    printf("=== BATTLE START! ===\n");

    while (player->hp > 0 && enemy->hp > 0) {

        int is_defending = 0;

        // =========================
        // プレイヤー表示
        // =========================
        printf("\n=== PLAYER ===\n");
        printf("HP: %d ", player->hp);
        print_hp_bar(player->hp, player->max_hp);
        printf(" MP: %d\n", player->mp);

        if (player->poison > 0) printf("【毒:%d】", player->poison);
        if (player->burn > 0) printf("【火傷:%d】", player->burn);

        printf("\nLv:%d EXP:%d/%d\n",
               player->level,
               player->exp,
               player->exp_to_next);

        // =========================
        // 敵表示
        // =========================
        printf("\n=== ENEMY ===\n");
        printf("%s HP:%d ", enemy->name, enemy->hp);
        print_hp_bar(enemy->hp, enemy->max_hp);
        printf("\n");

        // =========================
        // プレイヤー行動
        // =========================
        if (player->stun) {
            printf("スタンして動けない！\n");
            player->stun = 0;
        } else {
            int command;
            printf("1:攻撃 2:防御 3:回復 4:スキル\n");

            if (scanf("%d", &command) != 1) return 0;

            if (command == 1) {
                int damage = player->attack + rand() % 5 - 2;
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
                printf("防御！\n");

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

                printf("スキル！ %d ダメージ！\n", damage);
            }
        }

        // =========================
        // 撃破判定
        // =========================
        if (enemy->hp <= 0) {
            printf("%s を倒した！\n", enemy->name);

            if (enemy->type == DRAGON) {
                printf("🔥 ドラゴン討伐！ゲームクリア！🔥\n");
                return 1;
            }

            int exp_gain = 15;
            player->exp += exp_gain;

            while (player->exp >= player->exp_to_next) {
                level_up(player);
            }

            return 0;
        }

        // =========================
        // 敵行動
        // =========================
        if (enemy->stun) {
            printf("%s は動けない！\n", enemy->name);
            enemy->stun = 0;
            continue;
        }

        // 特殊行動
        if (enemy->type == SLIME && rand() % 4 == 0) {
            enemy->hp += 5;
            if (enemy->hp > enemy->max_hp)
                enemy->hp = enemy->max_hp;
            printf("スライムは回復した！\n");
            continue;
        }

        if (enemy->type == GOBLIN && rand() % 4 == 0) {
            if (player->poison == 0) {
                player->poison = 3;
                printf("毒矢を受けた！\n");
            }
        }

        if (enemy->type == ORC && rand() % 3 == 0) {
            int damage = enemy->attack * 2;
            printf("オークの強打！\n");
            player->hp -= damage;
            continue;
        }

        if (enemy->type == DRAGON && rand() % 3 == 0) {
            int damage = enemy->attack + 5;
            printf("🔥 炎攻撃！\n");
            player->hp -= damage;
            player->burn = 3;
            continue;
        }

        // 通常攻撃
        int damage = enemy->attack + rand() % 5 - 2;
        if (damage < 1) damage = 1;

        if (is_defending) {
            damage /= 2;
            printf("防御で軽減！\n");
        }

        player->hp -= damage;

        printf("%s の攻撃！ %d ダメージ\n", enemy->name, damage);

        if (player->hp <= 0) {
            printf("あなたは倒れた…\n");
            return 0;
        }

        // 状態異常
        if (player->poison > 0) {
            player->hp -= 3;
            player->poison--;
            printf("毒ダメージ\n");
        }

        if (player->burn > 0) {
            player->hp -= 4;
            player->burn--;
            printf("火傷ダメージ\n");
        }

        if (player->mp < player->max_mp)
            player->mp++;
    }

    return 0;
}
