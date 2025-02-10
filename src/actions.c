#include <stdio.h>
#include <stdlib.h>
#include "../include/actions.h"
#include "../include/battle.h"
#include "../include/player.h"
#include "../include/shop.h"
#include "../include/center.h"
#include "../include/save.h"

// Fonction pour afficher le menu des actions hors combat
void display_action_menu(Player *player) {
    int choice;

    while (1) {
        printf("\nWhat would you like to do, %s?\n", player->name);
        printf("1 - Into the Wild (Explore and fight Supémons)\n");
        printf("2 - In the Shop (Buy or sell items)\n");
        printf("3 - Supémon Center (Heal your Supémons)\n");
        printf("4 - Leave the Game\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("You head into the wild...\n");
                battle(player);  // Lancer un combat
                break;
            case 2:
                shop(player);  // Aller à la boutique
                break;
            case 3:
                heal_supemons(player);  // Soigner les Supémons
                break;
            case 4:
                printf("Do you want to save your progress before leaving? (1 - Yes, 2 - No): ");
                int save_choice;
                scanf("%d", &save_choice);
                if (save_choice == 1) {
                    printf("Saving the game...\n");
                    save_game(player);  // Appel de la fonction de sauvegarde
                }
                printf("Goodbye!\n");
                exit(0);  // Quitter le jeu
            default:
                printf("Invalid choice. Please select 1, 2, 3, or 4.\n");
        }
    }
}
