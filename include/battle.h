#ifndef BATTLE_H
#define BATTLE_H

#include "player.h"

// Déclaration des fonctions de combat
void battle(Player *player);
void attack(Supemon *attacker, Supemon *defender);
int run_away(Supemon *player_supemon, Supemon *wild_supemon);
int capture_supemon(Player *player, Supemon *wild_supemon);
void gain_experience(Supemon *player_supemon, int enemy_level);
void use_item_in_battle(Player *player);

#endif
