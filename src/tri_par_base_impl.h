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

template<typename Iterator, typename Fn>
void tri_comptage(Iterator first, Iterator last, Iterator output_first, Fn index_fn, size_t N) {
    //Vecteur de compteurs, selon le nombre de bits dans chaque bloc
    vector<unsigned> compteurs(size_t(pow(2,N)));
    unsigned index;
    unsigned temporaire;

    //Augmente les compteurs selon la valeur du premier bloc de bits de chaque valeur
    for (Iterator i = first; i <= last; ++i) {
        ++compteurs[index_fn(*i)];
    }

    index = 1;

    for (size_t i = 0; i < 10; ++i) {
        temporaire = compteurs[i];
        compteurs[i] = index;
        index += temporaire;
    }

    for (Iterator i = first; i <= last; ++i) {
        *(output_first + compteurs[index_fn(*i)] - 1) = *i;
        ++compteurs[index_fn(*i)];
    }
}

template<typename Iterator, size_t NBITS>
void tri_par_base(Iterator first, Iterator last) {

    //Contrôle que ce soit des unsigned dans les vecteurs
    using T = typename Iterator::value_type;
    static_assert(is_unsigned<T>::value);

    vector<unsigned> sortie(last - first + 1);

    //Appel le tri comptage pour chaque bloc de bits
    for (int i = 0; i < numeric_limits<unsigned>::digits / NBITS; ++i) {

       // cout << "Trie deja " << i << " fois" << endl;

        auto fn = SomeBits<unsigned long long>(NBITS, i);
        tri_comptage(first, last, sortie.begin(), fn, NBITS);

        //Remet les valeurs sorties dans le vecteur donné
        for (Iterator j = sortie.begin(); j < sortie.end(); ++j) {
            *(first + (j - sortie.begin())) = *j;
        }
    }
}

#endif //ASD_LABOS_2021_TRI_PAR_BASE_IMPL_H
