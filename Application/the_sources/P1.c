#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include "p1.h"
#include <math.h>
#include "ecrire_fichier.h"

struct structimg p3top1(struct structimg p3, char* nom_fichier){

    // On choisit une valeur alpha :
    float alpha = 0.5;

    struct structimg p1;
    p1.typeimg = P1;
  //  printf("P : %d\n", p1.typeimg);
    p1.largeur = p3.largeur;
  //  printf("Largeur : %d\n", p1.largeur);
    p1.hauteur = p3.hauteur;
  //  printf("Hauteur : %d\n", p1.hauteur);
    p1.vmax = 1;
  //  printf("vmax : %d\n", p1.vmax);

    p1.pixel = malloc(((p1.largeur)*p1.hauteur)*sizeof(uint64_t));
    // On calcule val :
    int vmax_cube = (int)pow(p3.vmax, 3);
    for (int j = 0; j < (p3.largeur*3)*(p3.hauteur) ; j = j+3) {
    float val = (p3.pixel[j] * p3.pixel[j+1] * p3.pixel[j+2])/(float)vmax_cube;
    //printf("val = %f\n", val);
    p1.pixel[j/3] = (val < alpha) ? 1 : 0;
  //  printf("p1.pxel = %ld\n", p1.pixel[j/3]);
        }

    //printf("\n\n\n");
    write_file(p1, nom_fichier);
    return p1;
}
