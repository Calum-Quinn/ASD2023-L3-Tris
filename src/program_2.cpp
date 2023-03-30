/* -----------------------------------------------------------------------------------
Nom du fichier : program_2.cpp (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 29.03.2023
Description    : Programme qui test le temps d'exécution du tri rapide et du tri par base
                 avec des vecteurs d'une taille différente.
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#include <iostream>
#include <vector>
#include <cmath>

#include "mesure.h"
#include "tri_rapide.h"
#include "tri_par_base.h"
#include "annexe.h"


using namespace std;

int main() {
   vector<unsigned> vec = {93, 45, 23, 143, 34, 0, 110, 67, 54, 76, 174};
   vector<int> vec1 = {4, 7, 3, 2, 1};

    // Test de la rapidité du Tri Rapide
    cout << "######################" << endl;
    cout << "######TRI RAPIDE######" << endl;
    cout << "######################" << endl;

    cout << "Temps d'execution : "
         << mesure_temps(vec1, tri_rapide<vector<int>::iterator>)
         << " ms";

    for (int i = 0; i < NBRETYPEVECTEURS; ++i) {
        for (int n = TAILLEDEBUT; n < TAILLEFIN; ++n) {
            vector<unsigned> vTriRapide = generateVector<unsigned>((size_t)pow(10.,(double)n), seed, typeTri(i));
            double rapide = mesure_temps(vTriRapide, tri_rapide<vector<unsigned>::iterator>);

            vector<unsigned> vTriBase = generateVector<unsigned>((size_t)pow(10.,(double)n), seed, typeTri(i));

            double base = mesure_temps(vTriBase, tri_par_base<vector<unsigned>::iterator, 1>);
            double base1 = mesure_temps(vTriBase, tri_par_base<vector<unsigned>::iterator, 2>);
            double base2 = mesure_temps(vTriBase, tri_par_base<vector<unsigned>::iterator, 4>);
            double base3 = mesure_temps(vTriBase, tri_par_base<vector<unsigned>::iterator, 8>);
            double base4 = mesure_temps(vTriBase, tri_par_base<vector<unsigned>::iterator, 16>);
        }
    }

    cout << endl << endl;

   return EXIT_SUCCESS;
}
