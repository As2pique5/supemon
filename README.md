# Supémon

**Supémon** est un jeu en ligne de commande (CLI) inspiré de l'univers de Pokémon, développé en **langage C**. Le projet consiste à capturer, entraîner et combattre des créatures appelées **Supémon** dans un environnement interactif.

---

## Sommaire
1. [Fonctionnalités](#fonctionnalités)
2. [Installation](#installation)
3. [Utilisation](#utilisation)
4. [Règles du jeu](#règles-du-jeu)
5. [Structure du projet](#structure-du-projet)
6. [Crédits](#crédits)

---

## Fonctionnalités

- **Création de partie** : Entrez votre nom et choisissez un Supémon de départ.
- **Chargement de partie** : Reprenez votre progression grâce au système de sauvegarde.
- **Exploration** : Partez à l'aventure pour combattre des Supémons sauvages.
- **Boutique** : Achetez et vendez des objets pour améliorer vos performances.
- **Centre Supémon** : Soignez vos Supémons gratuitement.
- **Combat tour par tour** : Affrontez des Supémons sauvages avec des stratégies variées.
- **Capturer des Supémons** : Tentez de capturer des Supémons pour agrandir votre équipe.
- **Montée en niveau** : Gagnez de l'expérience pour améliorer les statistiques de vos Supémons.
- **Sauvegarde et chargement de la progression**.

---

## Installation

### Prérequis
- **Compilateur GCC** (installé via les outils de ligne de commande Xcode sur MacOS)
- **Make** pour la compilation simplifiée

### Instructions
1. Clonez le dépôt :
   ```bash
   git clone https://github.com/As2pique5/supemon.git
   cd supemon
   ```

2. Compilez le projet :
   ```bash
   make
   ```

3. Lancez le jeu :
   ```bash
   ./supemon
   ```

---

## Utilisation

### Menu Principal
- **1 - New Game** : Créez une nouvelle partie.
- **2 - Load Game** : Chargez une partie précédemment sauvegardée.
- **3 - Exit** : Quittez le jeu (avec ou sans sauvegarde).

### Actions Hors Combat
- **Into the Wild** : Partez explorer et affrontez des Supémons sauvages.
- **In the Shop** : Achetez ou vendez des objets pour votre aventure.
- **Supémon Center** : Soignez vos Supémons gratuitement.
- **Leave the Game** : Quittez le jeu depuis le menu des actions (avec option de sauvegarde).

---

## Règles du Jeu

### 1. Supémons Disponibles
- **Supmander** : HP: 10 | Attack: 1 | Defense: 1 | Speed: 1
  - Moves: Scratch (3 damage), Grawl (+1 Attack)

- **Supasaur** : HP: 9 | Attack: 1 | Defense: 1 | Speed: 2
  - Moves: Pound (2 damage), Foliage (+1 Evasion)

- **Supirtle** : HP: 11 | Attack: 1 | Defense: 2 | Speed: 2
  - Moves: Pound (2 damage), Shell (+1 Defense)

### 2. Objets Disponibles
- **Potion** : +5 HP (100 Supcoins)
- **Super Potion** : +10 HP (300 Supcoins)
- **Rare Candy** : Monte d'un niveau (700 Supcoins)

### 3. Combats
- **Tour par tour** : Le Supémon avec la vitesse la plus élevée commence.
- **Actions possibles** :
  - Attaquer avec une compétence.
  - Changer de Supémon.
  - Utiliser un objet (max 4 par combat).
  - Tenter de capturer un Supémon.
  - Fuir le combat.

### 4. Capture des Supémons
La formule de capture est :

(Enemy_MaxHP - Enemy_HP) / Enemy_MaxHP - 0.5

Cette formule rend la capture difficile, surtout si le Supémon sauvage a plus de 50% de ses HP.

### 5. Montée en Niveau
- **Expérience** : Chaque victoire rapporte entre 100 et 500 XP multipliés par le niveau de l'adversaire.
- **Passage de niveau** : 500 XP pour passer du niveau 1 au niveau 2.
- **Statistiques** : Chaque niveau augmente les statistiques de 30%.

---

## Structure du Projet

```
Supemon/
├── src/
│   ├── main.c
│   ├── player.c
│   ├── supemon.c
│   ├── battle.c
│   ├── shop.c
│   ├── center.c
│   └── save.c
├── include/
│   ├── player.h
│   ├── supemon.h
│   ├── battle.h
│   ├── shop.h
│   ├── center.h
│   └── save.h
├── Makefile
├── README.md
└── savefile.txt (généré automatiquement lors de la sauvegarde)
```

---

## Crédits

- Projet réalisé dans le cadre d'un module de développement en **langage C**.
- Inspiré de l'univers de **Pokémon**.
- Développé par **DANG Job Césaire**.

---

## Licence

Ce projet est destiné à des fins académiques et d'apprentissage de l'établissement SupInfo.

