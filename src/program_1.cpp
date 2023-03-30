/* -----------------------------------------------------------------------------------
Nom du fichier : program_1.cpp (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 20.03.2023
Description    : Programme qui test le fonctionnement des différents tris
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

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


    cout << "######################" << endl;
    cout << "######TRI RAPIDE######" << endl;
    cout << "######################" << endl;

   cout << endl;

   //Test partition
   for(vector<unsigned> vec : vecteurs){
       vector<unsigned>::iterator i = partition<vector<unsigned>::iterator>(vec.begin(), vec.end());

       //Contrôle que les valeurs avant le pivot soit plus petit
       bool controle = true;
       for (vector<unsigned>::iterator j = vec.begin(); j != i; ++j) {
           if (*j > *i)
               controle = false;
       }
       //Contrôle que les valeurs après le pivot soit plus grand
       for (vector<unsigned>::iterator j = vec.end(); j != i; --j) {
           if (*j < *i)
               controle = false;
       }

       cout << boolalpha << "Partition OK ? : " << controle << endl;
   }

    //Test Tri Rapide
    for(vector<unsigned> vec : vecteurs){
        tri_rapide<vector<unsigned>::iterator>(vec.begin(), vec.end() - 1);

        cout << boolalpha << "Est trie ? "
             << is_sorted(vec.begin(), vec.end()) << endl;
    }

   cout << endl << endl;

   cout << "######################" << endl;
   cout << "#####TRI PAR BASE#####" << endl;
   cout << "######################" << endl;


   cout << endl;

   //Test tri par base qui comprend un test du tri comptage
   for (vector<unsigned> vec : vecteurs) {
       tri_par_base<vector<unsigned>::iterator,3>(vec.begin(),vec.end() - 1);
       cout << boolalpha << "Est trie ? " << is_sorted(vec.begin(), vec.end()) << endl;
   }

   return EXIT_SUCCESS;
}
