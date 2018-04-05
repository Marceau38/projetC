#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#define B_MASK (0x000000FF)
#define DECAL_R (16)
#define DECAL_V (8)
#define DEFAULT_PATH ("../bin/image.ppm")

//return le nom du fichier ou le nom du fichier par défaut si il n'y a pas de fichier en arguments
char *lignecommande(int argc, char *argv[], int* b, int* g, FILE **fichier) {
  // Faire un tableau des options
  // Si nom de fichier et réussi à ouvrir : pointeur
  char *nomfichier;
  for (int i = 1; i < argc; i++) {
    if (strcmp(argv[i], "-g") == 0){
      *g = 1;
    }
     else if (strcmp(argv[i], "-b") == 0) {
       *b = 1;
     }
     else {
       *fichier = fopen(argv[i], "r");
        nomfichier = argv[i];
     }
  }
  //si on a pas de nom de fichier, on redirige vers l'entrée standard.
  if (nomfichier == NULL) {
    *fichier = stdin;
    nomfichier = DEFAULT_PATH;
  }
  return nomfichier;
}

struct structimg lectureFichier(FILE* fichier){
  struct structimg image;
  //lecture du type P1,P2 ou P3
  char type[3];
  fgets(type, 3, fichier);
  if (type[1] == '3') {
  image.typeimg = P3;
  }
  else if (type[1] == '2') {
    image.typeimg = P2;
  }
  else if (type[1] == '1') {
    image.typeimg = P3;
  }
  else {
    printf("Erreur de fichier, ce n'est surement pas un fichier .ppm\n");
    exit(0);
  }

  // On stocke maintenant le nombre de Colonnes et de Lignes :
  fscanf(fichier, "%d %d", &image.largeur, &image.hauteur);

  // On stocke Vmax :
  fscanf(fichier, "%d", &image.vmax);

  // On stocke toutes les données dans un tableau : pixel
  image.pixel = malloc(((image.largeur)*image.hauteur)*sizeof(uint64_t)); // Il y a largeur nbLigne et hauteur nbColonne
  uint64_t k = 0; // Valeur à placer
  uint64_t rouge = 0;//valeur de lecture de couleurs
  uint64_t vert = 0;//on peut réutiliser 3 fois la même variable pour optimiser l'espace mémoire
  uint64_t bleu = 0;//mais utiliser 1 variable/couleur est plus lisible.
  int boucle = 0; // Position dans le tableau
  //lecture des couleurs tant qu'il y en a
  while (fscanf(fichier, "%" SCNd64 " ", &rouge) != EOF) {
    fscanf(fichier, "%" SCNd64 " ", &vert);
    fscanf(fichier, "%" SCNd64 " ", &bleu);
    k |= (bleu & B_MASK);
    k |= (vert & B_MASK)<<DECAL_V;
    k |= (rouge & B_MASK)<<DECAL_R;
    image.pixel[boucle] = k;
    //remise a 0 des variables de lecture
    rouge = 0; bleu = 0; vert = 0; k = 0;
    boucle++;
  }
  fclose(fichier);
  return image;
}
