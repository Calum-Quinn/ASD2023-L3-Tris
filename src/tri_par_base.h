/* -----------------------------------------------------------------------------------
Nom du fichier : tri_par_base.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 20.03.2023
Description    : Programme qui implémente le tri par base
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#ifndef TRI_PAR_BASE
#define TRI_PAR_BASE

#include <iterator>        //Utilisation des iterateurs
#include <type_traits>

#include "some_bits.h"

/**
 * @name 	            : tri_comptage
 *
 * @but 	            : trie le vecteur selon un certain nombre de bits
 * @param first         : iterateur du premier élément du vecteur à trier
 * @param last          : iterateur du dernier élément du vecteur à trier
 * @param output_first  : iterateur du premier élément du vecteur solution
 * @param N             : nombre de bits à utiliser
 * @return              : void
 * @throws              : NIL
 */
template<typename Iterator, typename Fn>
void tri_comptage(Iterator first, Iterator last, Iterator output_first, Fn index_fn, size_t N);


/**
 * @name 	            : tri_par_base
 *
 * @but 	            : trie le vecteur selon le prochain nombre de bits
 * @param first         : iterateur du premier élément du vecteur à trier
 * @param last          : iterateur du dernier élément du vecteur à trier
 * @return              : void
 * @throws              : NIL
 */
template<typename Iterator, size_t NBITS>
void tri_par_base(Iterator first, Iterator last);

#include "tri_par_base_impl.h"

#endif