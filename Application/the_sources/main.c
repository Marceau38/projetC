#include "struct.h"
#include <stdio.h>
#include <stdlib.h>



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

fclose(fichier);
  return 0;
}
