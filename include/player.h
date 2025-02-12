#ifndef PLAYER_H
#define PLAYER_H

#include "supemon.h" 

#define MAX_SUPEMONS 6
#define MAX_ITEMS 10

// Structure d'un objet
typedef struct {
    char name[50];  // Nom
    int effect;     // Effet
    int price;      // Prix 
} Item;

// Structure d'un joueur
typedef struct {
    char name[50];              // Nom du joueur
    Supemon supemons[MAX_SUPEMONS]; // Liste des Supémons
    int supemon_count;          // Supémons possédés
    int selected_supemon;       // Supémon sélectionné
    Item items[MAX_ITEMS];      // Inventaire
    int item_count;             // Nombre d'objets possédés
    int supcoins;               // Monnaie
} Player;

// Déclaration de la fonction pour créer un joueur
Player create_player();

#endif
