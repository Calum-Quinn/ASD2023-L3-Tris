/* -----------------------------------------------------------------------------------
Nom du fichier : tri_par_base.cpp (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 20.03.2023
Description    : Programme qui implémente le tri par base
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#include "tri_par_base.h"

using namespace std;

template<typename Iterator, typename Fn>
void tri_comptage(Iterator first, Iterator last, Iterator output_first, Fn index_fn, size_t N)
{

    // a compléter

}

template<typename Iterator, size_t NBITS>
void tri_par_base(Iterator first, Iterator last)
{
    using T = typename Iterator::value_type;
    static_assert(is_unsigned<T>::value);

    // a compléter

}