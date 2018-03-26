#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include "p2.h"

struct structimg p3top2(struct structimg p3, float a, float b, float c){
    struct structimg p2;
    p2.typeimg = P2;
    printf("P : %d\n", p2.typeimg);
    p2.largeur = p3.largeur;
    printf("Largeur : %d\n", p2.largeur);
    p2.hauteur = p3.hauteur;
    printf("Hauteur : %d\n", p2.hauteur);
    p2.vmax = p3.vmax;
    printf("vmax : %d\n", p2.vmax);
  //  p2.pixel
  int i = 0;
  int j = 0;
p2.pixel = malloc(((p2.largeur)*p2.hauteur)*sizeof(uint64_t));
for (j = 0; j < (p3.largeur*3)*(p3.hauteur) ; j = j+3) {
  uint64_t pixel = 0;
    for (i = 0; i < 3; i++) {
      if (i == 0) {pixel += (uint64_t)(a*p3.pixel[j+i]);} // Multiplier par le coeff a
      if (i == 1) {pixel += (uint64_t)(b*p3.pixel[j+i]);} // Multiplier par le coeff b
      if (i == 2) {pixel += (uint64_t)(c*p3.pixel[j+i]);} // Multiplier par le coeff c
}
      p2.pixel[j/3] = pixel;
      printf("P2 = %ld\n", p2.pixel[j/3] );
    }
    //printf("%d %d %d\n", (int)(p3.pixel[0]*a), (int)(p3.pixel[1]*b), (int)(p3.pixel[2]*c));
    //int pixel = (int)(a*p3.pixel[0]) + (int)(b*p3.pixel[1]) + (int)(c*p3.pixel[2]);
  //  printf("P2 : %d\n", pixel);
    return p2;
}
