#include <stdio.h>
#include <string.h>
#include "../include/shop.h"
#include "../include/player.h"

// Structure des objets disponibles en boutique
Item shop_items[] = {
    {"Potion", 5, 100},
    {"Super Potion", 10, 300},
    {"Rare Candy", 0, 700}  // Rare Candy n'ajoute pas de HP, mais augmente le niveau
};

int shop_items_count = 3;

// Fonction pour afficher les objets en boutique
void display_shop_items() {
    printf("\nWelcome to the Shop! Here are the available items:\n");
    for (int i = 0; i < shop_items_count; i++) {
        printf("%d - %s (Effect: +%d HP, Price: %d Supcoins)\n", i + 1, shop_items[i].name, shop_items[i].effect, shop_items[i].price);
    }
}

// Fonction pour acheter des objets
void buy_item(Player *player) {
    display_shop_items();
    int choice;
    printf("Enter the number of the item you want to buy (or 0 to cancel): ");
    scanf("%d", &choice);

    if (choice > 0 && choice <= shop_items_count) {
        Item selected_item = shop_items[choice - 1];
        if (player->supcoins >= selected_item.price) {
            if (player->item_count < MAX_ITEMS) {
                player->items[player->item_count] = selected_item;
                player->item_count++;
                player->supcoins -= selected_item.price;
                printf("You bought a %s!\n", selected_item.name);
            } else {
                printf("Your inventory is full!\n");
            }
        } else {
            printf("You don't have enough Supcoins!\n");
        }
    } else {
        printf("Purchase canceled.\n");
    }
}

// Fonction pour vendre des objets
void sell_item(Player *player) {
    if (player->item_count == 0) {
        printf("You have no items to sell.\n");
        return;
    }

    printf("\nYour items:\n");
    for (int i = 0; i < player->item_count; i++) {
        printf("%d - %s (Sell Price: %d Supcoins)\n", i + 1, player->items[i].name, player->items[i].price / 2);
    }

    int choice;
    printf("Enter the number of the item you want to sell (or 0 to cancel): ");
    scanf("%d", &choice);

    if (choice > 0 && choice <= player->item_count) {
        Item sold_item = player->items[choice - 1];
        player->supcoins += sold_item.price / 2;
        printf("You sold a %s for %d Supcoins!\n", sold_item.name, sold_item.price / 2);

        // Supprimer l'objet vendu de l'inventaire
        for (int i = choice - 1; i < player->item_count - 1; i++) {
            player->items[i] = player->items[i + 1];
        }
        player->item_count--;
    } else {
        printf("Sale canceled.\n");
    }
}

// Fonction principale de la boutique
void shop(Player *player) {
    int choice;
    while (1) {
        printf("\nWelcome to the Shop, %s! You have %d Supcoins.\n", player->name, player->supcoins);
        printf("1 - Buy Items\n");
        printf("2 - Sell Items\n");
        printf("3 - Leave Shop\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                buy_item(player);
                break;
            case 2:
                sell_item(player);
                break;
            case 3:
                printf("Leaving the shop...\n");
                return;
            default:
                printf("Invalid choice. Please select 1, 2, or 3.\n");
        }
    }
}
