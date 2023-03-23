/* -----------------------------------------------------------------------------------
Nom du fichier : tri_par_base_impl.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 20.03.2023
Description    : Programme qui implémente le tri par base
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#ifndef ASD_LABOS_2021_TRI_PAR_BASE_IMPL_H
#define ASD_LABOS_2021_TRI_PAR_BASE_IMPL_H

#include <vector>
#include <algorithm>
#include <cmath>


using namespace std;

unsigned cle(unsigned n, unsigned pos){
    unsigned digit;
    // Mettre la valeur voulue en dernière position
    n /= unsigned (pow(10.,double(pos - 1)));
    digit = n % 10;
    return digit;
}

template<typename Iterator, typename Fn>
void tri_comptage(Iterator first, Iterator last, Iterator output_first, Fn index_fn, size_t N) {
    //Pseudo code
//    fonction TriComptage(A,n,b,clé):
//      b c'est le nombre de compteurs (donc 10 -> 0-9)
//    C ← tableau de b compteurs à zéro
    vector<unsigned> compteurs(N);

    for (Iterator i = 0; i < last; ++i) {
        auto fn = SomeBits<unsigned long long>(N, i);
        *(output_first + i) = cle(fn(*(first + i)));
    }




////    pour tout e dans A
//    for(Iterator i = first; i <= last; ++i){
//        //    C[clé(e)] += 1
//        compteurs[index_fn(*i, N)] += 1;
//    }

//    //*(output_first + 1) = index_fn(*i, N);
////    idx ← 1
//unsigned index = 1;
//unsigned temp;
////    pour i de 1 à b
//    for(size_t i = 0; i < compteurs.size(); ++i) {
//        //    tmp ← C[i]
//        temp = compteurs[i];
//        //    C[i] ← idx
//        compteurs[i] = index;
//        //    idx += tmp
//        index += temp;
//    }
//
////    B = tableau de même taille que A
////    pour tout e dans A
// for (Iterator nombres = first; nombres <= last; ++nombres) {
//     //    B[C[clé(e)]] ← déplacer e
//     *(output_first + compteurs[index_fn(*nombres,N)] - 1) = *nombres;
//     //    C[clé(e)] += 1
//     ++compteurs[index_fn(*nombres,N)];
// }
}

template<typename Iterator, size_t NBITS>
void tri_par_base(Iterator first, Iterator last) {

    using T = typename Iterator::value_type;
    static_assert(is_unsigned<T>::value);


    vector<unsigned> sortie(last - first);

//    tri_comptage(first, last, sortie.begin(), cle, numeric_limits<T>::digits / NBITS);




//    unsigned max = *max_element(first,last);
//
//    size_t digits = size_t(log10(max) + 1);
//
//    for (unsigned i = 1; i <= digits; --i) {
//        tri_comptage(first,last, sortie.begin(), cle,i);
//        for (int j = 0; j < last - first; ++j) {
//            *(first + j) = sortie[j];
//        }
//    }

    //Pseudo code
//    fonction triParBase(T, d):
//    Pour i allant de d à 1
//      Trier avec un tri stable le tableau T selon le i-ème chiffre

}

#endif //ASD_LABOS_2021_TRI_PAR_BASE_IMPL_H
