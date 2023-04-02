/* -----------------------------------------------------------------------------------
Nom du fichier : mesure.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 24.03.2023
Description    : Programme pour mesurer le temps pour un tri
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#ifndef ASD_LABOS_2021_MESURE_H
#define ASD_LABOS_2021_MESURE_H

#include <vector>

/**
 * @name 	            : mesure_temps
 *
 * @but 	               : mesure le temps que prends une fonction pour trier un vecteur
 * @param v1            : vecteur à trier
 * @param f             : fonction de tri à évaluer
 * @return              : temps de tri
 * @throws              : NIL
 */
template<typename T, typename Fn>
double mesure_temps(std::vector<T>& v1, Fn f);

#include "mesure_impl.h"

#endif //ASD_LABOS_2021_MESURE_H
