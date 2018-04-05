#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include "p1.h"
#include <math.h>
#include "ecrire_fichier.h"

#define R_MASK (0x00FF0000)
#define V_MASK (0x0000FF00)
#define B_MASK (0x000000FF)

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
    float val;
    for (int j = 0; j < (p3.largeur)*(p3.hauteur) ; j++) {
      val = ((p3.pixel[j]&R_MASK>>16) * (p3.pixel[j]&V_MASK>>8) * (p3.pixel[j]&B_MASK))/(float)vmax_cube;
      p1.pixel[j] = (val < alpha) ? 1 : 0; // On enregistre la valeur du pixel
        }

    write_file(p1, nom_fichier); // Fonction qui écrit la structure dans un fichier
    return p1;
}
