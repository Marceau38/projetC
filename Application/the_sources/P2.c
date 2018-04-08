//DECAMPS Marceau, LAGRANGE Nathan : Binome 4
#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include "p2.h"
#include "ecrire_fichier.h"

#define R_MASK (0x00FF0000)
#define V_MASK (0x0000FF00)
#define B_MASK (0x000000FF)
#define DECAL_R (16)
#define DECAL_V (8)

struct structimg p3top2(struct structimg p3, float a, float b, float c, char* nom_fichier){
  struct structimg p2; // Création de la structure stockant l'image binaire
  p2.typeimg = P2; // Le type de l'image est P2
  p2.largeur = p3.largeur; // La largeur et la hauteur restent la même
  p2.hauteur = p3.hauteur; // Il y a autant de pixel qu'avant
  p2.vmax = p3.vmax; // vmax vaut le meme que P3 puisque la valeur max est 255. Le niveau de gris est défini entre 0 et 255

  p2.pixel = malloc(((p2.largeur)*p2.hauteur)*sizeof(uint64_t)); // On alloue un tableau d'uint64_t

  for (int j = 0; j < (p3.largeur)*(p3.hauteur) ; j++) { // Boucle parcourant chaque pixel
    uint64_t pixel = 0;
    pixel += (uint64_t)(a*(p3.pixel[j]&R_MASK>>DECAL_R)); // Multiplier par le coeff a Rouge
    pixel += (uint64_t)(b*(p3.pixel[j]&V_MASK>>DECAL_V)); // Multiplier par le coeff b Vert
    pixel += (uint64_t)(c*(p3.pixel[j]&B_MASK)); // Multiplier par le coeff c Bleu

    p2.pixel[j] = pixel; // Enregistrement du pixel pour p2
  }

  write_file(p2, nom_fichier); // Fonction qui écrit la structure dans un fichier
  return p2;
}
