//DECAMPS Marceau, LAGRANGE Nathan : Binome 4
#include "struct.h"
#include <stdio.h>
#include <inttypes.h>
#include "p2.h"
#include "p1.h"
#include "util.h"



int main (int argc, char *argv[]) {
  int param_b = 0;
  int param_g = 0;
  FILE *fichier = NULL;
  char *nomfichier = lignecommande(argc, argv, &param_b, &param_g, &fichier);
  struct structimg image = lectureFichier(fichier);

  //// On pose les valeurs de a , b, et c
  float a = 0.299;
  float b = 0.587;
  float c = 0.114;
  if (param_g) {
    p3top2(image, a, b, c, nomfichier);
  }
  if (param_b) {
    p3top1(image, nomfichier);
  }
  return 0;
}
