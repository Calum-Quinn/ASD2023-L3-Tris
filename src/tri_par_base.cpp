/* -----------------------------------------------------------------------------------
Nom du fichier : tri_par_base.cpp (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 20.03.2023
Description    : Programme qui implémente le tri par base
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#include <vector>
#include <algorithm>
#include "tri_par_base.h"


using namespace std;

template<typename T>
size_t cle(T n){

}

template<typename Iterator, typename Fn>
void tri_comptage(Iterator first, Iterator last, Iterator output_first, Fn index_fn, size_t N) {
    //Pseudo code
//    fonction TriComptage(A,n,b,clé):
//    C ← tableau de b compteurs à zéro
    vector<int> c(N, 0);
//    pour tout e dans A
    for(Iterator i = first; i < last; ++i){
        //    C[clé(e)] += 1
        c[cle(*i)] += 1;
    }

//    idx ← 1
//    pour i de 1 à b
//    tmp ← C[i]
//    C[i] ← idx
//    idx += tmp
//    B = tableau de même taille que A
//    pour tout e dans A
//    B[C[clé(e)]] ← déplacer e
//    C[clé(e)] += 1
//    return B
}

template<typename Iterator, size_t NBITS>
void tri_par_base(Iterator first, Iterator last) {

    using T = typename Iterator::value_type;
    static_assert(is_unsigned<T>::value);


    unsigned max = *max_element(first,last);

    //Pseudo code
//    fonction triParBase(T, d):
//    Pour i allant de d à 1
//for (int i = d; i > 0; --i) {
//
//}
//    Trier avec un tri
//    stable le tableau T
//    selon le i-ème chiffre

}