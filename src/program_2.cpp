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

    const int TAILLEDEBUT = 1;
    const int TAILLEFIN = 6;
    const int NBRETYPEVECTEURS = 4;
    const size_t NBREBITMIN = 0;
    const size_t NBREBITMAX = 4;
    const unsigned SEED = 67;

    //Vecteurs pour emregistrer les résultats des mesures
    vector<int> valeurs(TAILLEFIN - TAILLEDEBUT + 1);
    vector<vector<double>> mesures (6);

    // Test de la rapidité du Tri Rapide
    cout << "######################" << endl;
    cout << "######TRI RAPIDE######" << endl;
    cout << "######################" << endl;

    for (int i = 0; i < NBRETYPEVECTEURS; ++i) {
        for (int n = TAILLEDEBUT; n < TAILLEFIN; ++n) {

            valeurs[size_t(n - 1)] = (unsigned)pow(10.,(double)n);

            vector<unsigned> vTriRapide = generateVector<unsigned>((size_t)pow(10.,(double)n), SEED, typeTri(i));
            mesures[0].push_back(mesure_temps(vTriRapide, tri_rapide<vector<unsigned>::iterator>));

            vector<unsigned> vTriBase = generateVector<unsigned>((size_t)pow(10.,(double)n), SEED, typeTri(i));

            cout << "Tri rapide fini" << endl;

            //Effectue les mesures pour les différentes taille de bloc de bits
            mesures[1].push_back(mesure_temps(vTriBase, tri_par_base<vector<unsigned>::iterator, 1>));
            mesures[2].push_back(mesure_temps(vTriBase, tri_par_base<vector<unsigned>::iterator, 2>));
            mesures[3].push_back(mesure_temps(vTriBase, tri_par_base<vector<unsigned>::iterator, 4>));
            mesures[4].push_back(mesure_temps(vTriBase, tri_par_base<vector<unsigned>::iterator, 8>));
            mesures[5].push_back(mesure_temps(vTriBase, tri_par_base<vector<unsigned>::iterator, 16>));
        }
    }

    exporter_csv<double>("C:/Users/calum/OneDrive/Documents/Etudes/HEIG/Semestre2/ASD/Laboratoires/ASD2023-L3-Tris/rapport/csv/example.csv",valeurs,mesures);

    cout << endl << endl;

    return EXIT_SUCCESS;
}
