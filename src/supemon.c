#include <stdio.h>
#include <string.h>
#include "../include/supemon.h"

// Fonction pour initialiser un Supémon
Supemon create_supemon(const char *name) {
    Supemon s;
    strcpy(s.name, name);
    s.level = 1;
    s.experience = 0;

    // Initialisation des statistiques selon le Supémon choisi
    if (strcmp(name, "Supmander") == 0) {
        s.hp = s.max_hp = 10;
        s.attack = 1;
        s.defense = 1;
        s.evasion = 1;
        s.accuracy = 2;
        s.speed = 1;
    } else if (strcmp(name, "Supasaur") == 0) {
        s.hp = s.max_hp = 9;
        s.attack = 1;
        s.defense = 1;
        s.evasion = 3;
        s.accuracy = 2;
        s.speed = 2;
    } else if (strcmp(name, "Supirtle") == 0) {
        s.hp = s.max_hp = 11;
        s.attack = 1;
        s.defense = 2;
        s.evasion = 2;
        s.accuracy = 1;
        s.speed = 2;
    }

    return s;
}

// Fonction pour afficher les Supémons disponibles
void display_supemon_choices() {
    printf("Choose your Supémon:\n");
    printf("1 - Supmander (HP: 10, Attack: 1, Defense: 1, Speed: 1)\n");
    printf("2 - Supasaur (HP: 9, Attack: 1, Defense: 1, Speed: 2)\n");
    printf("3 - Supirtle (HP: 11, Attack: 1, Defense: 2, Speed: 2)\n");
}
