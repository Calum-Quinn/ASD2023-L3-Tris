/* -----------------------------------------------------------------------------------
Nom du fichier : tri_rapide.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 20.03.2023
Description    : Programme qui implémente le tri rapide
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#ifndef TRI_RAPIDE
#define TRI_RAPIDE

/**
 * @name 	            : partition
 *
 * @but 	            : partitionne un vecteur selon un pivot aléatoire (petits à gauche et grands à droite)
 * @param first         : iterateur du premier élément du vecteur à trier
 * @param last          : iterateur du dernier élément du vecteur à trier
 * @return              : iterateur du pivot après placement
 * @throws              : NIL
 */
template<typename Iterator>
Iterator partition(Iterator first, Iterator last);

/**
 * @name 	            : tri_rapide
 *
 * @but 	            : tri un vecteur en appelant récursivement partition selon un pivot aléatoire
 * @param first         : iterateur du premier élément du vecteur à trier
 * @param last          : iterateur du dernier élément du vecteur à trier
 * @return              : void
 * @throws              : NIL
 */
template<typename Iterator>
void tri_rapide(Iterator first, Iterator last);

#include "tri_rapide_impl.h"

#endif