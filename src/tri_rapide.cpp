/* -----------------------------------------------------------------------------------
Nom du fichier : tri_rapide.cpp (xxx = h ou cpp)
Auteur(s)      : Ewan Mariaux, Calum Quinn, Dario Vasques
Date creation  : 20.03.2023
Description    : Programme qui implémente le tri rapide
Remarque(s)    : <à compléter>
Compilateurs   : Apple clang version 14.0.0 (clang-1400.0.29.102) (Dario)
               : Mingw-w64 g++ 12.2.0 (Calum et Ewan)
----------------------------------------------------------------------------------- */

#include "tri_rapide.h"

using namespace std;

template<typename Iterator>
Iterator partition(Iterator first, Iterator last) {



//    template <typename T>
//    int partition (T tableau[], int debut, int fin) {
//
//        int p = fin;
//        int i = debut;
//        int j = p-1;
//
//        while(true) {
//            // avancer i
//            while (tableau[i] < tableau[p])
//                ++i;
//
//            // reculer j
//            while (debut <= j and tableau[j] > tableau[p])
//                --j;
//
//            // indices rejoints ou croisés
//            if (i >= j)
//                break;
//
//            // échanger les valeurs
//            swap(tableau[i], tableau[j]);
//        }
//
//        // mettre la valeur de pivot à sa place
//        swap(tableau[i], tableau[p]);
//
//        return i;
//    }
}

template<typename Iterator>
void tri_rapide(Iterator first, Iterator last) {

    Iterator p; //pivot

    while(last - first > 0){

      //  p = nbreAleaoire;

      swap(*last, *p);

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