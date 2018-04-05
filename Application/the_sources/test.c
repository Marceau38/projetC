#include "../the_headers/struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
//#include "p2.h"
//#include "p1.h"


FILE* lignecommande(int argc, char *argv[]) {
  // Faire un tableau des options
  // Si nom de fichier et réussi à ouvrir : pointeur
  FILE* fichier = NULL;
  int b = 0;
  int g = 0;
  for (int i = 0; i < argc; i++) {
    if (strcmp(argv[i], "-g") == 0){
      g = 1;
    }
     if (strcmp(argv[i], "-b") == 0) {
       b = 1;
     }

  }
  fichier = fopen (argv[2], "r");
  if (fichier == NULL) {
    /* Le fichier n'existe pas */
    fichier = stdin; /* On lit donc sur l'entrée standard */
  }
  return fichier;
}

struct structimg lecturefichier(fichier) {
  struct structimg image;
  /* On va créer la structure de donnée du fichier */
  char typetest[3];
  fgets(typetest, 3, fichier);

//On commence par charger le type
if (typetest[1] == '3') {
  image.typeimg = P3;
}
else if (typetest[1] == '2') {
  image.typeimg = P2;
}
else if (typetest[1] == '1') {
  image.typeimg = P3;
}
else {
  printf("Erreur de fichier, ce n'est surement pas un fichier .ppm\n");
  exit(0);
}

// On stocke maintenant le nombre de Colonnes et de Lignes :
fscanf(fichier, "%d %d", &image.largeur, &image.hauteur);
//printf("Largeur=%d Hauteur=%d\n", image.largeur, image.hauteur);

// On stocke Vmax :
fscanf(fichier, "%d", &image.vmax);
//printf("Vmax = %d\n", image.vmax);

return image;
}



int main(int argc, char *argv[]) {
  lecturefichier(lignecommande(argc, argv));
}
