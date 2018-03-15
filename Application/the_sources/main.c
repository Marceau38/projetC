#include struct.h
#include <stdio.h>
#include <stdlib.h>



int main (int argc, char *argv[]) {
  FILE* fichier = NULL;

  fichier = fopen (argv[1], "r");

  if (fichier == NULL)  {
      printf("Impossible d'ouvrir le fichier %s", argv[1]);
      exit(0); // Arret du programme
  }

  int P3;
  int P = fscanf(fichier, "%d", &P3);


  return 0;
}
