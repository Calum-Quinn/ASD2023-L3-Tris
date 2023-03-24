
#include <iostream>
#include <vector>

#include "tri_rapide.h"
#include "tri_par_base.h"

using namespace std;

int main() {

   //-------------------
   // Test Tri Rapide
   cout << "###########TRI RAPIDE###########" << endl;
   vector<int> v = {1 ,3, 4, 2, 9, 5, 11, 8, 6, 7};

   for(int i : v){
      cout << i << " ";
   }
   cout << endl;

   tri_rapide<vector<int>::iterator>(v.begin(), v.end() -1);

   for(int i : v){
      cout << i << " ";
   }
   cout << endl << endl;

   //-------------------
   // Test Tri par base
   cout << "###########TRI PAR BASE###########" << endl;

   vector<unsigned> vec = {93, 45, 23, 76, 34, 0, 110, 67, 54};

   for (unsigned i : vec) {
      cout << i << " ";
   }

   cout << endl;

   tri_par_base<vector<unsigned>::iterator,3>(vec.begin(),vec.end() - 1);

   for (unsigned i : vec) {
      cout << i << " ";
   }

   return 0;
}
