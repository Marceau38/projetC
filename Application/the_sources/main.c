#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <p2.h>



int main (int argc, char *argv[]) {
  FILE* fichier = NULL;

  fichier = fopen (argv[1], "r");

/*  if (fichier == NULL)  {
      printf("Impossible d'ouvrir le fichier %s", argv[1]);
      exit(0); // Arret du programme
  }
  */
  char typetest[3];
  char typeimg[2] = "";
  fgets(typetest, 3, fichier);
  //fscanf(fichier, "%s", typetest);
  printf("%s\n", typetest);
//  fscanf(fichier, "%c%c", &typeimg[0], &typeimg[1]);
//  printf("%c%c\n", typeimg[0], typeimg[1]);
  //int P    = fscanf(fichier, "%d", &P3);


  struct structimg image;

//On commence par charger le type
if (typetest[1] == '3') {
  image.typeimg = P3;
  printf("%d\n", image.typeimg);
}
else if (typetest[1] == '2') {
  image.typeimg = P2;
  printf("%d\n", image.typeimg);
}
else if (typetest[1] == '1') {
  image.typeimg = P3;
  printf("%d\n", image.typeimg);
}
else {
  printf("Erreur de fichier, ce n'est surement pas un fichier .ppm\n");
  exit(0);
}


// On stocke maintenant le nombre de Colonnes et de Lignes :
fscanf(fichier, "%d %d", &image.largeur, &image.hauteur);
printf("Largeur=%d Hauteur=%d\n", image.largeur, image.hauteur);

// On stocke Vmax :
fscanf(fichier, "%d", &image.vmax);
printf("Vmax = %d\n", image.vmax);

// On stocke toutes les données dans un tableau : pixel
image.pixel = malloc(((image.largeur*3)*image.hauteur)*sizeof(uint64_t)); // Il y a largeur*3 nb/ligne et hauteur nb/colonne
int k = 0; // Valeur à placer
int boucle = 0; // Position dans le tableau
int tab[3] = {0};
  while (fscanf(fichier, "%d ", &k) != EOF) {
  image.pixel[boucle] = k;
  printf("%ld\n", image.pixel[boucle]);
  boucle++;
}


fclose(fichier);
//// On pose les valeurs de a , b, et c
p3top2(image, 0.299, 0.587, 0.114);
  return 0;
}
