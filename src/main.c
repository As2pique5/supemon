#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/player.h"
#include "../include/actions.h"
#include "../include/battle.h"
#include "../include/save.h"

// Affichage menu principal
void display_main_menu() {
    printf("Hello !\n Welcome in Supémon World!\n");
    printf("1 - New Game\n");
    printf("2 - Load Game\n");
    printf("3 - Exit\n");
}

// Fonction principale
int main() {
    int choice;
    srand(time(NULL));  // Génération des valeurs aléatoires
    Player player;  // Déclaration du joueur

    while (1) {  // Boucle du menu
        display_main_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                player = create_player();  // Création du joueur et choix du Supémon
                display_action_menu(&player);  // Affiche le menu des actions hors combat
                break;
            case 2:
                player = load_game();  // Chargement de la partie sauvegardée
                display_action_menu(&player);
                break;
            case 3:
                printf("Do you want to save your progress before exiting? (1 - Yes, 2 - No): ");
                int save_choice;
                scanf("%d", &save_choice);
                if (save_choice == 1) {
                    save_game(&player);
                }
                printf("Goodbye!\n");
                exit(0);  // Quitter
            default:
                printf("Invalid choice. Please select 1, 2, or 3.\n");
        }
    }

    return 0;
}
