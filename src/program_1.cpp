
#include <iostream>
#include <vector>

#include "tri_rapide.h"
#include "tri_par_base.h"

using namespace std;




int main() {

   const unsigned seed = 67;


    vector<vector<unsigned>> vecteurs = {
            generateVector<unsigned>(100, seed, typeTri::CROISSANT),
            generateVector<unsigned>(100, seed, typeTri::DECROISSANT),
            generateVector<unsigned>(100, seed, typeTri::ALEATOIRE),
            generateVector<unsigned>(100, seed, typeTri::PRESQUETRIE)
    };

    //-------------------
    // Test Tri Rapide
    cout << "######################" << endl;
    cout << "######TRI RAPIDE######" << endl;
    cout << "######################" << endl;

   cout << endl;

   bool controlePartition = true;

   for(vector<unsigned> vec : vecteurs){
       vector<unsigned>::iterator i = partition<vector<unsigned>::iterator>(vec.begin(), vec.end());

       //controle que la fonction partition soit OK.
       bool controle = true;
       for (vector<unsigned>::iterator j = vec.begin(); j != i; ++j) {
           if (*j > *i)
               controle = false;
       }
       for (vector<unsigned>::iterator j = vec.end(); j != i; --j) {
           if (*j < *i)
               controle = false;
       }

       cout << boolalpha << "partition OK ? : " << controle << endl;
   }

    for(vector<unsigned> vec : vecteurs){
        tri_rapide<vector<unsigned>::iterator>(vec.begin(), vec.end() - 1);

        cout << "test" << endl;
        cout << boolalpha << "Est trie ? "
             << is_sorted(vec.begin(), vec.end()) << endl;
    }






   cout << endl << endl;

   //-------------------
   // Test Tri par base
   cout << "######################" << endl;
   cout << "#####TRI PAR BASE#####" << endl;
   cout << "######################" << endl;



   cout << endl;

   //Test tri par base
   for (vector<unsigned> vec : vecteurs) {
       tri_par_base<vector<unsigned>::iterator,3>(vec.begin(),vec.end() - 1);
       cout << boolalpha << "Est trie ? " << is_sorted(vec.begin(), vec.end()) << endl;
   }


    //Test tri comptage
   for (vector<unsigned> vec : vecteurs) {

       vector<unsigned> sortie(vec.end() - 1 - vec.begin() + 1);
       vector<unsigned> test(sortie.size());

       for (int i = 0; i < numeric_limits<unsigned>::digits / 2; ++i) {
           auto fn = SomeBits<unsigned long long>(2, i);
           tri_comptage(vec.begin(), vec.end() - 1, sortie.begin(), fn, 2);

           for (vector<unsigned>::iterator j = sortie.begin(); j < sortie.end(); ++j) {
               *(vec.begin() + (j - sortie.begin())) = *j;
           }

         /*  for (vector<unsigned>::iterator j = sortie.begin(); j < sortie.end(); ++j) {
                *(vec.begin() + (j - sortie.begin())) = SomeBits<unsigned long long>(2, j);
           }*/
       }
   }


   return 0;
}
