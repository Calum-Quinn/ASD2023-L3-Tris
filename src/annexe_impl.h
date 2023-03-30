/* -----------------------------------------------------------------------------------
Nom du fichier : annexe_impl.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 28.03.2023
Description    : Algorithme pour générer des vecteurs correspondant au type de tri
                 et exporter des données en csv.
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#ifndef ASD_LABOS_2021_ANNEXE_IMPL_H
#define ASD_LABOS_2021_ANNEXE_IMPL_H

#include <vector>    //Utilisation des vecteurs
#include <random>    //Génération nombre aléatoire
#include <iostream>

using namespace std;

random_device                  rand_dev;
default_random_engine          generator(rand_dev());

int nbrAleatoire(int min, int max){
    uniform_int_distribution<int>  distr(min, max);
    return distr(generator);
}


template <typename T>
std::vector<T> generateVector(size_t n, const unsigned seed, typeTri tri) {
    std::vector<T> vecteur(n);

    //Vecteur croissant de 0 à n-1
    if(tri == typeTri::CROISSANT) {
        for (size_t i = 0; i < vecteur.size(); ++i) {
            vecteur[i] = T(i);
        }
    }
        //Vecteur décroissant de n-1 à 0
    else if(tri == typeTri::DECROISSANT) {
        for (size_t i = 0; i < vecteur.size(); ++i) {
            vecteur[i] = T(n - (i + 1));
        }
    }
        //Vecteur aléatoire avec de 0 à n-1
    else if (tri == typeTri::ALEATOIRE) {
        for (size_t i = 0; i < vecteur.size(); ++i) {
            vecteur[i] = T(i);
        }
        shuffle(vecteur.begin(), vecteur.end(), default_random_engine(seed));
    }
        //Vecteur ressemblant à trié
    else if (tri == typeTri::PRESQUETRIE) {
        srand((seed));
        for (size_t i = 0; i < vecteur.size(); ++i) {
            vecteur[i] = T(double(i)/2. + double(rand()%n)/2.); // Somme pondérée entre tri croissant et aléatoire
        }
    }

    return vecteur;
}

template <typename T>
void exporter_csv(std::string const& filename, const std::vector<int>& n_values, const std::vector<std::vector<T>>& mesures) {

    std::ofstream out(filename);

    if(not out.is_open()) {
        std::cerr << "Pas pu ouvrir le fichier en écriture" << std::endl;
        return;
    }

    out << "n";

    for(int n : n_values)
        out << ";" << n;

    out << std::endl;

    for(size_t i = 0; i < mesures.size(); ++i) {
        switch (i) {
            case 0 : out << "TriRapide"; break;
            case 1 : out << "TriParBase"; break;
            default: break;
        }

        for (T d : mesures[i])
            out << ";" << d;
            out << std::endl;
        }

}

#endif //ASD_LABOS_2021_ANNEXE_IMPL_H
