#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include "p2.h"
#include "ecrire_fichier.h"

struct structimg p3top2(struct structimg p3, float a, float b, float c, char* nom_fichier){
    struct structimg p2; // Création de la structure stockant l'image binaire
    p2.typeimg = P2; // Le type de l'image est P2
    p2.largeur = p3.largeur; // La largeur et la hauteur restent la même
    p2.hauteur = p3.hauteur; // Il y a autant de pixel qu'avant
    p2.vmax = p3.vmax; // vmax vaut le meme que P3 puisque la valeur max est 255. Le niveau de gris est défini entre 0 et 255

p2.pixel = malloc(((p2.largeur)*p2.hauteur)*sizeof(uint64_t)); // On alloue un tableau d'uint64_t
for (int j = 0; j < (p3.largeur)*(p3.hauteur) ; j++) { // Boucle parcourant chaque pixel
  uint64_t pixel = 0;
  //printf("test\n");
  //  for (int i = 0; i < 3; i++) { // Boucle parcourant les 3 couleurs de chaque pixel
      pixel += (uint64_t)(a*(p3.pixel[j]&0x00FF0000>>16)); // Multiplier par le coeff a Rouge
      pixel += (uint64_t)(b*(p3.pixel[j]&0x0000FF00>>8)); // Multiplier par le coeff b Vert
      pixel += (uint64_t)(c*(p3.pixel[j]&0x000000FF)); // Multiplier par le coeff c Bleu
//}
      p2.pixel[j] = pixel; // Tous les 3 pixels de P3, on ne veut qu'1 pixel dans P1

    }

  write_file(p2, nom_fichier); // Fonction qui écrit la structure dans un fichier
  return p2;
}
