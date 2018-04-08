//DECAMPS Marceau, LAGRANGE Nathan : Binome 4
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
    //on duplique le nom de fichier avec un nouveau format. 
    //Ancienement "nom_fichier[z-2] = 'b';" mais bug avec entrée standard (??)
    char* new_name = malloc(z*sizeof(char));
    for(int i = 0; i<z; i++){
      new_name[i] = (i==z-2)? 'b' : nom_fichier[i];
    }new_name[z]='\0'; //on s'assure que le nom du fichier se termine ou l'on souhaite (utile pour le pipe)
    fichier = fopen(new_name  , "w");
    typeimage = "P1";
    printf("On sauve l'image au format PBM dans le fichier %s\n", new_name);
  }
  if (p.typeimg ==2) { // Si on veut convertir vers une image en niveau de gris
    char* new_name = malloc(z*sizeof(char));
    for(int i = 0; i<z; i++){
      new_name[i] = (i==z-2)? 'g' : nom_fichier[i];
    }new_name[z]='\0';
    fichier = fopen(new_name, "w");
    typeimage = "P2";
    printf("On sauve l'image au format PGM dans le fichier %s\n", new_name);
}

//On sauvegarde toutes les données
fputs(typeimage, fichier);
fputs("\n", fichier);
char largeur[4];
char hauteur[4];
sprintf(largeur, "%d", p.largeur); /// Passage d'un int en char
sprintf(hauteur, "%d", p.hauteur); // Passage d'un int en char
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
