/* -----------------------------------------------------------------------------------
Nom du fichier : tri_rapide_impl.h (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 20.03.2023
Description    : Programme qui implémente le tri rapide
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#ifndef ASD_LABOS_2021_TRI_RAPIDE_IMPL_H
#define ASD_LABOS_2021_TRI_RAPIDE_IMPL_H



#include "tri_rapide.h"
#include "annexe.h"
#include <random>

using namespace std;




template<typename Iterator>
Iterator partition(Iterator first, Iterator last) {

    Iterator p = last;
    Iterator i = first;
    Iterator j = last -1;

    while(true){
        //avancer i
        while(*i < *p)
            ++i;

        //reculer j
        while(j - first >= 0 and *j > *p) {
            --j;
        }
        //indice rejoints ou croisés
        if(j - i <= 0) {
            break;
        }

        //échanger les valeurs
        swap(*i, *j);
    }

    swap(*i, *p);

    return i;
}

template<typename Iterator>
void tri_rapide(Iterator first, Iterator last) {

    Iterator p; //pivot

    while(last - first > 0) {

        p = first + (nbrAleatoire(0, last - first));

        swap(*last, *p);

        Iterator i = partition<Iterator>(first, last);

        if (i - first < last - i) {
            tri_rapide<Iterator>(first, i - 1);
            first = i + 1;
        } else{
            tri_rapide<Iterator>(i+1, last);
            last = i - 1;
        }
    }



//    fonction TriRapide(A,lo,hi)
//    tant que lo < hi
//    p ← choisir l’élément pivot
//    permuter A(hi) et A(p)
//    i ← Partition(A,lo,hi)
//    si i-lo < hi-i, alors
//    TriRapide(A,lo,i-1)
//    lo ← i+1
//    sinon,
//            TriRapide(A,i+1,hi)
//    hi ← i-1
//    fin si
//    fin tant que




//    template <typename T>
//    void tri_rapide (T tableau[], int taille, bool trace) {
//        tri_rapide_rec(tableau, taille, 0, taille-1, trace);
//    }
//
//---------------------------------------------------------
//    template <typename T>
//    void tri_rapide_rec(T tableau[], int taille, int debut, int fin, bool trace) {
//        if(debut < fin) {
//            // pivot systématiquement en position hi
//            int pivot = partition(tableau, debut, fin);
//
//            // affiche les résultats intermédiaires de la partition
//            if (trace) {
//                cout << debut << " " << pivot << " " << fin << "    ";
//                display_tab(tableau, taille);
//                cout << endl;
//            }
//
//            // appels récursifs
//            tri_rapide_rec(tableau, taille, debut,   pivot-1, trace);
//            tri_rapide_rec(tableau, taille, pivot+1, fin    , trace);
//        }
//
//        // cas simples
//        if (debut == fin and trace) {
//            cout << debut << " " << debut << " " << fin << "    ";
//            display_tab(tableau, taille);
//            cout << endl;
//        }
//    }
}


#endif //ASD_LABOS_2021_TRI_RAPIDE_IMPL_H
