#ifndef SUPEMON_H
#define SUPEMON_H

// Structure pour représenter un Supémon
typedef struct {
    char name[50];      // Nom du Supémon
    int level;          // Niveau du Supémon
    int experience;     // Points d'expérience
    int hp;             // Points de vie actuels
    int max_hp;         // Points de vie maximum
    int attack;         // Attaque actuelle
    int defense;        // Défense actuelle
    int evasion;        // Évasion actuelle
    int accuracy;       // Précision actuelle
    int speed;          // Vitesse
} Supemon;

// Fonctions pour créer et afficher les Supémons
Supemon create_supemon(const char *name);
void display_supemon_choices();

#endif
