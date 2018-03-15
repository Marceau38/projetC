#include <stdint.h>

typedef enum type type;
enum type {P1, P2, P3};

struct structimg {
  enum type typeimg;/// Défini si c'est une image P1=1 ou P2=2 ou P3=3
  uint32_t largeur; /// Largeur de l'image (en pixel)
  uint32_t hauteur; /// Hauteur de l'image (en pixel)
  int vmax; /// Valeur maximale d'une donnée d'un pixel
  uint64_t* pixel; // Tableau dynamique stockant les données de l'image
};
