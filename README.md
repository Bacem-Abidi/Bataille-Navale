# ⚓ Bataille Navale Simplifiée

Mini-projet en langage C — jeu de bataille navale en mode console.
**ISET Charguia** · Département Technologies de l'Informatique · Atelier de Programmation Structurée (1ère année, 2026-2027)

**Réalisé par :** Yomna Ben Allala, Becem Abidi — **Encadrante :** Mme Ichraf Hamdech — **Groupe 1**

## Description

L'ordinateur cache **5 bateaux** à des positions aléatoires dans une grille de **10 × 10**. Le joueur propose une ligne et une colonne à chaque tour et dispose d'un nombre limité d'essais pour tous les retrouver.

- **Victoire** : les 5 bateaux sont trouvés.
- **Défaite** : tous les essais sont utilisés.

## Fonctionnalités

- Menu principal : Nouvelle partie, Afficher les règles, Quitter
- 3 niveaux de difficulté : **Facile** (25 essais), **Moyen** (20 essais), **Difficile** (15 essais)
- Placement aléatoire sans doublon (`rand()` / `srand(time(NULL))`)
- Vérification des coordonnées (0 à 9) ; une case déjà jouée ne coûte aucun essai
- Affichage en mode texte avec statistiques après chaque tir
- Grille finale qui révèle les bateaux non trouvés

## Symboles de la grille

| Symbole | Signification |
|:-------:|---------------|
| `.` | Case inconnue |
| `X` | Bateau touché |
| `O` | Tir raté |
| `B` | Bateau non trouvé (affiché en fin de partie) |

## Compilation et exécution

Aucune dépendance : seule la bibliothèque standard C est utilisée.

```bash
git clone https://github.com/Bacem-Abidi/Bataille-Navale.git
cd Bataille-Navale
gcc -Wall -o bataille_navale BatailleNavale.c
./bataille_navale          # Linux / macOS
bataille_navale.exe        # Windows
```

## Exemple de partie

```
   0 1 2 3 4 5 6 7 8 9
  ---------------------
0| . . . . . . . . . .
1| . . O . . . . . . .
2| . . . . . X . . . .
3| . . . . . . . . . .
...
Entrez la ligne (0 a 9)   :
```

## Structure du code

Le programme est découpé en 13 fonctions :

| Fonction | Rôle |
|----------|------|
| `initialiserMer` | Met la mer à 0 (aucun bateau) |
| `placerBateaux` | Place 5 bateaux aléatoirement, dans des cases différentes |
| `initialiserGrilleAffichage` | Remplit la grille du joueur avec des points |
| `afficherGrille` | Affiche la grille sans révéler les bateaux |
| `afficherGrilleFinale` | Affiche la grille complète en fin de partie |
| `tirer` | Traite un tir (touché, raté, déjà joué) |
| `tousBateauxTrouves` | Teste la victoire |
| `afficherStatistiques` | Affiche bateaux trouvés et essais restants |
| `choisirDifficulte` | Choix du niveau, retourne le nombre d'essais |
| `afficherMenu` / `afficherRegles` | Menu principal et règles |
| `jouerPartie` | Déroulement complet d'une partie |
| `main` | Boucle du menu principal |

## Pistes d'amélioration

- Mieux contrôler les saisies non numériques
- Bateaux de plusieurs cases
- Mode deux joueurs
