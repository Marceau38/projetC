#include "ecrire_fichier.h"
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct structimg;
int write_file(struct structimg p, char* nom_fichier) {


  int z = strlen(nom_fichier); /// Longueur du nom du fichier


  char *typeimage;
  FILE* fichier = NULL;
  if (p.typeimg == 1) { // Si on veut convertir vers une image binaire
    nom_fichier[z-2] = 'b';
    fichier = fopen(nom_fichier, "w");
    typeimage = "P1";
    printf("On sauve l'image au format PBM dans le fichier %s\n", nom_fichier);
    //printf("fichier :: %s\n", nom_fichier);
  }
  if (p.typeimg ==2) { // Si on veut convertir vers une image en niveau de gris
    nom_fichier[z-2] = 'g';
    fichier = fopen(nom_fichier, "w");
    typeimage = "P2";
    printf("On sauve l'image au format PGM dans le fichier %s\n", nom_fichier);
  //  printf("fichier :: %s\n", nom_fichier);
}
//printf("typeimg = %s\n", typeimage);
fputs(typeimage, fichier);
fputs("\n", fichier);
char largeur[4];
char hauteur[4];
sprintf(largeur, "%d", p.largeur); /// Passage d'un int en char
sprintf(hauteur, "%d", p.hauteur); // Passage d'un int en char
//printf("largeur = %s\n", largeur);
fputs(largeur, fichier);
fputs(" ", fichier);
fputs(hauteur, fichier);
fputs("\n", fichier);
char vmax[4];
sprintf(vmax, "%d", p.vmax);
fputs(vmax, fichier);
fputs("\n", fichier);
for (int i = 0; i < (p.largeur * p.hauteur); i++) {
  char tmp[4];
  sprintf(tmp, "%ld", p.pixel[i]);
  fputs(tmp, fichier);
  fputs(" ", fichier);
}

//fputs(p.largeur + " " + p.hauteur, fichier);

  fclose(fichier);
  return 0;
}
