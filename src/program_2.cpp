
#include <iostream>
#include <vector>

#include "mesure.h"
#include "tri_rapide.h"
#include "tri_par_base.h"

using namespace std;

int main() {
   //vector<unsigned> vec = {93, 45, 23, 143, 34, 0, 110, 67, 54, 76, 174};
   vector<unsigned> vec = {93, 45, 23, 140, 234, 32, 1};

   for(int i : vec){
      cout << i << " ";
   }

   cout << endl;

   cout << mesure_temps(vec, tri_rapide<vector<unsigned>::iterator>);
   //tri_rapide<vector<unsigned>::iterator>(vec.begin(), vec.end() - 1);

   cout << endl;

   for(int i : vec){
      cout << i << " ";
   }

   return 0;
}
