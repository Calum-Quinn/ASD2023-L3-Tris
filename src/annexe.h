/* -----------------------------------------------------------------------------------
Nom du fichier : annexe.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 28.03.2023
Description    : Algorithme pour générer des vecteurs correspondant au type de tri
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#ifndef ASD_LABOS_2021_ANNEXE_H
#define ASD_LABOS_2021_ANNEXE_H

#include <string>       // Utilisation du string
#include <vector>       // Utilisation des vecteurs
#include <fstream>      // Pour exporter les donnnées en CSV

enum class typeTri {CROISSANT, DECROISSANT, ALEATOIRE, PRESQUETRIE};

// Nombre aléatoire
int nbrAleatoire(int min, int max);


/**
 * @name 	               : generateVector
 *
 * @but 	               : genère les vecteurs devant être triés
 * @param n	               : taille du vecteur
 * @param const seed       : seed pour la génération de nombres aléatoires
 * @param tri              : type de vecteur à produire
 * @return                 : vecteur généré
 * @throws                 : NIL
 */

template <typename T>
std::vector<T> generateVector(size_t n, unsigned seed, typeTri tri);

/**
 * @name 	                : export_csv
 *
 * @but 	                   : export de données dans un fichier csv
 * @param filename          : emplacement du fichier de destination
 * @param n_values          : nombre de colonnes
 * @param mesures           : données qui seront affichées dans le fichier
 * @return                  : NIL
 * @throws                  : NIL
 */
template <typename T>
void exporter_csv(std::string const& filename, const std::vector<int>& n_values, const std::vector<std::vector<T>>& mesures);

#include "annexe_impl.h"

#endif //ASD_LABOS_2021_ANNEXE_H