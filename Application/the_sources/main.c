#include "struct.h"
#include <stdio.h>
#include <inttypes.h>
#include "p2.h"
#include "p1.h"
#include "util.h"



int main (int argc, char *argv[]) {

int b = 0;
int g = 0;
FILE *fichier = NULL;
char *nomfichier = lignecommande(argc, argv, &b, &g, &fichier);
struct structimg image = lectureFichier(fichier);

//// On pose les valeurs de a , b, et c
float a = 0.299;
float k = 0.587;
float c = 0.114;
if (g == 1) {
  p3top2(image, a, k, c, nomfichier);
}
if (b == 1) {
  p3top1(image, nomfichier);
}

  return 0;
}



// 1 : Fonction lire la ligne de commande et analyser
// 2 : Lire le fichier et charge structure de donnée
// 3 : Traitement
