#include <stdio.h>
#include <string.h>
#include "../include/player.h"
#include "../include/supemon.h"

// Fonction pour créer un nouveau joueur
Player create_player() {
    Player p;
    printf("Enter your name: ");
    scanf("%s", p.name);  // Saisie du nom du joueur

    // Afficher les Supémons disponibles
    display_supemon_choices();

    int choice;
    printf("Enter the number of your choice: ");
    scanf("%d", &choice);

    // Attribution du Supémon choisi
    switch (choice) {
        case 1:
            p.supemons[0] = create_supemon("Supmander");
            break;
        case 2:
            p.supemons[0] = create_supemon("Supasaur");
            break;
        case 3:
            p.supemons[0] = create_supemon("Supirtle");
            break;
        default:
            printf("Invalid choice. You will get Supmander by default.\n");
            p.supemons[0] = create_supemon("Supmander");
            break;
    }

    p.supemon_count = 1;         // un seul Supémon au départ
    p.selected_supemon = 0;      // celui sélectionné
    p.supcoins = 500;            // 500 Supcoins initiaux
    p.item_count = 0;            // Pas d'objets au début

    printf("Welcome %s! You have chosen %s.\n", p.name, p.supemons[0].name);

    return p;
}
