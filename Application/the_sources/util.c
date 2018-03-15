#include "struct.h"
#include <stdio.h>
#include <stdlib.h>

void modif_type(struct structimg p, enum type val){
    p.typeimg = val;
}
void modif_taille(struct structimg p, uint32_t largeur, uint32_t hauteur){
    p.largeur = largeur;
    p.hauteur = hauteur;
}
void modif_pixel(struct structimg p, uint64_t* pixel){
    p.pixel = pixel;
}


//return une structimg avec les valeurs associées.
struct structimg init_struct(enum type val, uint32_t largeur, uint32_t hauteur, uint64_t* pixel){
    //creation d'une struct resultat avec une taille de tableau correcte
    struct structimg result = malloc(sizeof(struct structimg)) + (sizeof(uint64_t) * largeur * hauteur);
    modif_type(result, val);
    modif_taille(result, hauteur, largeur);
    modif_pixel(result, pixel);
}