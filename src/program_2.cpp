
#include <iostream>
#include <vector>

#include "mesure.h"
#include "tri_rapide.h"
#include "tri_par_base.h"

using namespace std;

int main() {
   vector<unsigned> vec = {93, 45, 23, 143, 34, 0, 110, 67, 54, 76, 174};
   vector<int> vec1 = {4, 7, 3, 2, 1};

   // Test de la rapidité du Tri Rapide
   cout << "######################" << endl;
   cout << "######TRI RAPIDE######" << endl;
   cout << "######################" << endl;

   cout  << "Temps d'exécution : "
         << mesure_temps(vec1, tri_rapide<vector<int>::iterator>)
         << " ms";

   cout << endl << endl;

   // Test de la rapidité du Tri par base
   cout << "######################" << endl;
   cout << "#####TRI PAR BASE#####" << endl;
   cout << "######################" << endl;

   cout  << "Temps d'exécution : "
         << mesure_temps(vec, tri_par_base<vector<unsigned>::iterator, 3>)
         << " ms";

   return 0;
}
