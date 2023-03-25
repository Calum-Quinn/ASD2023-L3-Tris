//
// Created by Dario Vasques on 24.03.23.
//

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
