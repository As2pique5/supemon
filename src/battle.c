#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "../include/battle.h"
#include "../include/player.h"
#include "../include/supemon.h"
#include "../include/shop.h"

// Fonction pour lancer un combat contre un Supémon sauvage
void battle(Player *player) {
    printf("\nYou venture into the wild...\n");

    // Générer un Supémon sauvage aléatoire
    Supemon wild_supemon;
    int random_supemon = rand() % 3;
    printf("Random number for wild Supemon: %d\n", random_supemon);  // Debug info

    if (random_supemon == 0) {
        wild_supemon = create_supemon("Supmander");
    } else if (random_supemon == 1) {
        wild_supemon = create_supemon("Supasaur");
    } else {
        wild_supemon = create_supemon("Supirtle");
    }

    printf("A wild %s appeared! (HP: %d, Attack: %d, Defense: %d)\n",
           wild_supemon.name, wild_supemon.hp, wild_supemon.attack, wild_supemon.defense);

    Supemon *player_supemon = &player->supemons[player->selected_supemon];

    // Déterminer qui commence en fonction de la vitesse
    int player_turn = player_supemon->speed >= wild_supemon.speed ? 1 : 0;

    // Vérification des points de vie pour éviter des erreurs de boucle
    printf("Player's Supemon: %s (HP: %d/%d)\n", player_supemon->name, player_supemon->hp, player_supemon->max_hp);
    printf("Wild Supemon: %s (HP: %d/%d)\n", wild_supemon.name, wild_supemon.hp, wild_supemon.max_hp);


    while (player_supemon->hp > 0 && wild_supemon.hp > 0) {
        printf("Entering the battle loop...\n");  // Debug info

        if (player_turn) {
            // Tour du joueur
            printf("\nYour turn! What will you do?\n");
            printf("1 - Attack\n2 - Use Item\n3 - Capture\n4 - Run Away\n");
            int choice;
            scanf("%d", &choice);

            switch (choice) {
                case 1:
                    attack(player_supemon, &wild_supemon);
                    break;
                case 2:
                    use_item_in_battle(player);
                    break;
                case 3:
                    if (capture_supemon(player, &wild_supemon)) {
                        return;
                    }
                    break;
                case 4:
                    if (run_away(player_supemon, &wild_supemon)) {
                        return;
                    }
                    break;
                default:
                    printf("Invalid choice.\n");
            }
        } else {
            // Tour de l'ennemi
            printf("\n%s attacks!\n", wild_supemon.name);
            attack(&wild_supemon, player_supemon);
        }

        // Vérifier la fin du combat
        if (wild_supemon.hp <= 0) {
            printf("\nYou defeated %s!\n", wild_supemon.name);
            int reward = (rand() % 401) + 100;  // Entre 100 et 500 Supcoins
            player->supcoins += reward;
            printf("You earned %d Supcoins!\n", reward);
            gain_experience(player_supemon, wild_supemon.level);
            return;
        }

        if (player_supemon->hp <= 0) {
            printf("\nYour Supémon fainted! You lost the battle.\n");
            return;
        }

        player_turn = !player_turn;  // Changer de tour
    }
}

// Fonction pour attaquer un Supémon
void attack(Supemon *attacker, Supemon *defender) {
    int damage = (attacker->attack * 3) / defender->defense;
    if (damage <= 0) damage = 1;  // Assurer qu'il y a au moins 1 dégât

    defender->hp -= damage;
    if (defender->hp < 0) defender->hp = 0;

    printf("%s deals %d damage to %s! (%d HP remaining)\n",
           attacker->name, damage, defender->name, defender->hp);
}

// Fonction pour tenter de fuir le combat
int run_away(Supemon *player_supemon, Supemon *wild_supemon) {
    int chance = (player_supemon->speed * 100) / (player_supemon->speed + wild_supemon->speed + 1);
    int roll = rand() % 100;
    if (roll < chance + 20) {
        printf("You successfully ran away!\n");
        return 1;
    } else {
        printf("Failed to run away!\n");
        return 0;
    }
}

// Fonction pour tenter de capturer un Supémon
int capture_supemon(Player *player, Supemon *wild_supemon) {
    float capture_rate = (float)(wild_supemon->max_hp - wild_supemon->hp) / wild_supemon->max_hp - 0.5;
    int roll = rand() % 100;

    if (roll < (capture_rate * 100)) {
        if (player->supemon_count < MAX_SUPEMONS) {
            player->supemons[player->supemon_count] = *wild_supemon;
            player->supemon_count++;
            printf("You captured %s!\n", wild_supemon->name);
            return 1;  // Capture réussie
        } else {
            printf("Your team is full! You can't capture more Supémons.\n");
            return 0;
        }
    } else {
        printf("Capture failed!\n");
        return 0;  // Capture échouée
    }
}

// Fonction pour donner de l'expérience après un combat gagné
void gain_experience(Supemon *player_supemon, int enemy_level) {
    int experience_gained = (rand() % 401 + 100) * enemy_level;
    player_supemon->experience += experience_gained;
    printf("%s gained %d experience points!\n", player_supemon->name, experience_gained);

    // Vérification de la montée de niveau
    if (player_supemon->experience >= 500) {
        player_supemon->level++;
        player_supemon->experience -= 500;
        player_supemon->max_hp += player_supemon->max_hp * 0.3;
        player_supemon->attack += player_supemon->attack * 0.3;
        player_supemon->defense += player_supemon->defense * 0.3;
        player_supemon->hp = player_supemon->max_hp;  // Restaurer la santé complète après le niveau
        printf("%s leveled up to level %d!\n", player_supemon->name, player_supemon->level);
    }
}

// Fonction pour utiliser un objet en combat
void use_item_in_battle(Player *player) {
    if (player->item_count == 0) {
        printf("You have no items to use!\n");
        return;
    }

    printf("\nYour items:\n");
    for (int i = 0; i < player->item_count; i++) {
        printf("%d - %s (Effect: +%d HP)\n", i + 1, player->items[i].name, player->items[i].effect);
    }

    int choice;
    printf("Enter the number of the item to use (or 0 to cancel): ");
    scanf("%d", &choice);

    if (choice > 0 && choice <= player->item_count) {
        Item selected_item = player->items[choice - 1];
        Supemon *current_supemon = &player->supemons[player->selected_supemon];

        if (strcmp(selected_item.name, "Rare Candy") == 0) {
            // Rare Candy augmente le niveau du Supémon
            current_supemon->level++;
            current_supemon->max_hp += current_supemon->max_hp * 0.3;
            current_supemon->attack += current_supemon->attack * 0.3;
            current_supemon->defense += current_supemon->defense * 0.3;
            printf("%s leveled up to level %d!\n", current_supemon->name, current_supemon->level);
        } else {
            // Les potions soignent le Supémon
            current_supemon->hp += selected_item.effect;
            if (current_supemon->hp > current_supemon->max_hp) {
                current_supemon->hp = current_supemon->max_hp;
            }
            printf("You used %s! %s is now at %d/%d HP.\n", selected_item.name, current_supemon->name, current_supemon->hp, current_supemon->max_hp);
        }

        // Retirer l'objet utilisé de l'inventaire
        for (int i = choice - 1; i < player->item_count - 1; i++) {
            player->items[i] = player->items[i + 1];
        }
        player->item_count--;
    } else {
        printf("Item use canceled.\n");
    }
}
