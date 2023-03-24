
#include <iostream>
#include <vector>

#include "mesure.h"
#include "tri_rapide.h"
#include "tri_par_base.h"

using namespace std;

int main() {
   vector<unsigned> vec = {93, 45, 23, 143, 34, 0, 110, 67, 54, 76, 174};
   vector<int> vec1 = {93, 45, 23, 143, 34, 0, 110};

   for(int i : vec1){
      cout << i << " ";
   }

   cout << endl;

   //cout << mesure_temps(vec1, tri_rapide<vector<unsigned>::iterator>);
   tri_rapide<vector<int>::iterator>(vec1.begin(), vec1.end() - 1);

   cout << endl;

   for(int i : vec1){
      cout << i << " ";
   }

   cout << endl << endl;

   cout << "######################" << endl;
   cout << "#####TRI PAR BASE#####" << endl;
   cout << "######################" << endl;

   cout << mesure_temps(vec, tri_par_base<vector<unsigned>::iterator, 3>);

   return 0;
}
