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

template<typename Iterator>
Iterator partition(Iterator first, Iterator last);

template<typename Iterator>
void tri_rapide(Iterator first, Iterator last);

#include "tri_rapide_impl.h"

#endif