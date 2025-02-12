#include <stdio.h>
#include "../include/save.h"
#include "../include/player.h"
#include <stdlib.h>
#include <string.h>
#include <errno.h>


// Fonction sauvegarde
void save_game(Player *player) {
    FILE *file = fopen("savefile.txt", "w");
    if (file == NULL) {
        printf("Error saving the game : %s\n", strerror(errno));
        return;
    }

    // Sauvegarde info joueur
    fprintf(file, "%s\n", player->name);
    fprintf(file, "%d\n", player->supcoins);
    fprintf(file, "%d\n", player->supemon_count);

    // Sauvegarde Supémons
    for (int i = 0; i < player->supemon_count; i++) {
        Supemon s = player->supemons[i];
        fprintf(file, "%s %d %d %d %d %d %d %d %d %d\n",
                s.name, s.level, s.experience, s.hp, s.max_hp,
                s.attack, s.defense, s.evasion, s.accuracy, s.speed);
    }

    // Sauvegarde objets
    fprintf(file, "%d\n", player->item_count);
    for (int i = 0; i < player->item_count; i++) {
        Item item = player->items[i];
        fprintf(file, "%s %d %d\n", item.name, item.effect, item.price);
    }

    fclose(file);
    printf("Game saved successfully!\n");
}


// Fonction charger partie
Player load_game() {
    Player player;
    FILE *file = fopen("savefile.txt", "r");
    if (file == NULL) {
        printf("No saved game found. Starting a new game instead.\n");
        player.supemon_count = 0;
        player.item_count = 0;
        player.supcoins = 0;
        strcpy(player.name, "Unknown");
        return player;
    }

    // Chargement info joueur
    fscanf(file, "%s", player.name);
    fscanf(file, "%d", &player.supcoins);
    fscanf(file, "%d", &player.supemon_count);

    // Chargement Supémons
    for (int i = 0; i < player.supemon_count; i++) {
        Supemon *s = &player.supemons[i];
        fscanf(file, "%s %d %d %d %d %d %d %d %d %d",
               s->name, &s->level, &s->experience, &s->hp, &s->max_hp,
               &s->attack, &s->defense, &s->evasion, &s->accuracy, &s->speed);
    }

    // Chargement objets
    fscanf(file, "%d", &player.item_count);
    for (int i = 0; i < player.item_count; i++) {
        Item *item = &player.items[i];
        fscanf(file, "%s %d %d", item->name, &item->effect, &item->price);
    }

    fclose(file);
    printf("Game loaded successfully! Welcome back, %s!\n", player.name);
    return player;
}
