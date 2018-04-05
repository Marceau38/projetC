#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include "p1.h"
#include <math.h>
#include "ecrire_fichier.h"

struct structimg p3top1(struct structimg p3, char* nom_fichier){

    // On choisit une valeur alpha :
    float alpha = 0.5;

    struct structimg p1; // Création de la structure stockant l'image binaire
    p1.typeimg = P1; // Le type de l'image est P1
    p1.largeur = p3.largeur; // La largeur et la hauteur restent la même
    p1.hauteur = p3.hauteur; // Il y a autant de pixel qu'avant
    p1.vmax = 1; // Vmax vaut 1 puisque c'est la valeur max que l'on peut avoir dans un fichier binaire

    p1.pixel = malloc(((p1.largeur)*p1.hauteur)*sizeof(uint64_t)); // On alloue un tableau d'uint64_t
    // On calcule val :
    int vmax_cube = (int)pow(p3.vmax, 3);
    for (int j = 0; j < (p3.largeur)*(p3.hauteur) ; j++) {
      float val = ((p3.pixel[j]&0x00FF0000>>16) * (p3.pixel[j]&0x0000FF00>>8) * (p3.pixel[j]&0x000000FF))/(float)vmax_cube;
      p1.pixel[j] = (val < alpha) ? 1 : 0; // Tous les 3 pixels de P3, on ne veut qu'1 pixel dans P1
        }

    write_file(p1, nom_fichier); // Fonction qui écrit la structure dans un fichier
    return p1;
}
