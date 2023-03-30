
#include <iostream>
#include <vector>

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
