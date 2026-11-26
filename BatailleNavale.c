#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialiserMer(int mer[10][10]) {
  int i, j;
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      mer[i][j] = 0;
    }
  }
}

void placerBateaux(int mer[10][10]) {
  int bateauxPlaces = 0;
  int ligne, colonne;

  while (bateauxPlaces < 5) {
    ligne = rand() % 10;
    colonne = rand() % 10;

    if (mer[ligne][colonne] == 0) {
      mer[ligne][colonne] = 1;
      bateauxPlaces++;
    }
  }
}

void initialiserGrilleAffichage(char grille[10][10]) {
  int i, j;
  for (i = 0; i < 10; i++) {
    for (j = 0; j < 10; j++) {
      grille[i][j] = '.';
    }
  }
}

void afficherGrille(char grille[10][10]) {
  int i, j;

  printf("\n   0 1 2 3 4 5 6 7 8 9\n");
  printf("  ---------------------\n");
  for (i = 0; i < 10; i++) {
    printf("%d| ", i);
    for (j = 0; j < 10; j++) {
      printf("%c ", grille[i][j]);
    }
    printf("\n");
  }
}

void afficherGrilleFinale(int mer[10][10], char grille[10][10]) {
  int i, j;

  printf("\n=== GRILLE FINALE ===\n");
  printf("   0 1 2 3 4 5 6 7 8 9\n");
  printf("  ---------------------\n");
  for (i = 0; i < 10; i++) {
    printf("%d| ", i);
    for (j = 0; j < 10; j++) {
      if (grille[i][j] == 'X') {
        printf("X ");
      } else if (grille[i][j] == 'O') {
        printf("O ");
      } else if (mer[i][j] == 1) {
        printf("B ");
      } else {
        printf(". ");
      }
    }
    printf("\n");
  }
  printf(
      "Legende : X = Touche | O = Rate | B = Bateau non trouve | . = Vide\n");
}

int tirer(int mer[10][10], char grille[10][10], int ligne, int colonne) {
  int tir;
  if (grille[ligne][colonne] != '.') {
    printf("\n[!] Vous avez deja tire sur cette case !\n");
    tir = 0;
  } else if (mer[ligne][colonne] == 1) {
    printf("\n[OK] Touche !\n");
    grille[ligne][colonne] = 'X';
    tir = 1;
  } else {
    printf("\n[X] Rate !\n");
    grille[ligne][colonne] = 'O';
    tir = 1;
  }
  return tir;
}

int tousBateauxTrouves(int score) {
  if (score >= 5) {
    return 1;
  }
  return 0;
}

void afficherStatistiques(int score, int essaisRestants, int choix) {
  printf("+-----------------------------------+\n");
  printf("| Bateaux trouves : %d / 5           |\n", score);
  printf("| Essais restants : %d / %d          |\n", essaisRestants, choix);
  printf("+-----------------------------------+\n");
}

int choisirDifficulte() {
  int choixDiff;

  printf("\n--- CHOIX DU NIVEAU DE DIFFICULTE ---\n");
  printf("1. Facile    (5 bateaux - 25 essais)\n");
  printf("2. Moyen     (5 bateaux - 20 essais)\n");
  printf("3. Difficile (5 bateaux - 15 essais)\n");

  do {
    printf("Votre niveau (1 a 3) : ");
    scanf("%d", &choixDiff);
  } while (choixDiff < 1 || choixDiff > 3);

  if (choixDiff == 1) {
    return 25;
  } else if (choixDiff == 2) {
    return 20;
  } else {
    return 15;
  }
}

void afficherMenu() {
  printf("\n====================================\n");
  printf("         BATAILLE NAVALE\n");
  printf("====================================\n");
  printf("1. Nouvelle partie\n");
  printf("2. Afficher les regles\n");
  printf("3. Quitter\n");
  printf("====================================\n");
  printf("Votre choix : ");
}

void afficherRegles() {
  printf("\n--- REGLES DU JEU ---\n");
  printf("Objectif : retrouver 5 bateaux caches dans une grille de 10x10.\n");
  printf("Niveaux : Facile (25 essais), Moyen (20 essais), Difficile (15 "
         "essais).\n");
  printf("Symboles :\n");
  printf("  . : Case inconnue\n");
  printf("  X : Bateau trouve (Touche)\n");
  printf("  O : Tir rate\n");
  printf("  B : Bateau non trouve (affiche en fin de partie)\n");
}

void jouerPartie() {
  int mer[10][10];
  char grille[10][10];
  int ligne, colonne;
  int score = 0;
  int essaisRestants, choix;
  int tir;

  choix = choisirDifficulte();
  essaisRestants = choix;
  initialiserMer(mer);
  placerBateaux(mer);
  initialiserGrilleAffichage(grille);

  while (essaisRestants > 0 && !tousBateauxTrouves(score)) {
    afficherGrille(grille);

    do {
      printf("Entrez la ligne (0 a 9)   : ");
      scanf("%d", &ligne);
      printf("Entrez la colonne (0 a 9) : ");
      scanf("%d", &colonne);
      if (ligne < 0 || ligne > 9 || colonne < 0 || colonne > 9) {
        printf("Coordonnees invalides ! Choisissez entre 0 et 9.\n");
      }
    } while (ligne < 0 || ligne > 9 || colonne < 0 || colonne > 9);

    tir = tirer(mer, grille, ligne, colonne);
    if (grille[ligne][colonne] == 'X') {
      score++;
    }
    if (tir == 1) {
      essaisRestants--;
    }
    afficherStatistiques(score, essaisRestants, choix);
  }

  printf("\n====================================\n");
  if (tousBateauxTrouves(score)) {
    printf("  Bravo! Vous avez gagne.\n");
  } else {
    printf("  Game Over. Vous avez trouve seulement %d bateaux sur 5.\n",
           score);
  }
  printf("====================================\n");

  afficherGrilleFinale(mer, grille);
}

int main() {
  int choix;

  srand(time(NULL));

  do {
    afficherMenu();
    scanf("%d", &choix);

    if (choix == 1) {
      jouerPartie();
    } else if (choix == 2) {
      afficherRegles();
    } else if (choix == 3) {
      printf("\nMerci d'avoir joue. Au revoir !\n");
    } else {
      printf("\nChoix invalide, veuillez reessayer.\n");
    }
  } while (choix != 3);

  return 0;
}
