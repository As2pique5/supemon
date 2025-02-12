#include <stdio.h>
#include "../include/player.h"
#include "../include/center.h"

// Soins à tous les Supémons
void heal_supemons(Player *player) {
    printf("\nWelcome to the Supémon Center, %s!\n", player->name);
    for (int i = 0; i < player->supemon_count; i++) {
        player->supemons[i].hp = player->supemons[i].max_hp;  // Restaure les PV au maximum
        printf("%s has been healed to full health!\n", player->supemons[i].name);
    }
    printf("All your Supémons are now fully healed!\n");
}
