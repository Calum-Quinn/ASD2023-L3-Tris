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

	const unsigned SEED = 67;
	const size_t NB_TRIS = 4;
	const size_t TAILLE_VEC = 100;

	vector<vector<unsigned>> vecteurs(NB_TRIS);

	//Génération des vecteurs à triés avec différents remplissages
	for(size_t i = 0; i < vecteurs.size(); ++i){
		vecteurs.at(i) = generateVector<unsigned>(TAILLE_VEC, SEED, typeTri(i));
	}

	cout << "######################" << endl;
	cout << "######TRI RAPIDE######" << endl;
	cout << "######################" << endl;

	cout << endl;

	//Test partition
	for(vector<unsigned> vec : vecteurs){
		auto i = partition<vector<unsigned>::iterator>(vec.begin(), vec.end());

		//Contrôle que les valeurs avant le pivot soit plus petit
		bool controle = true;
		for (auto j = vec.begin(); j != i; ++j) {
			if (*j > *i)
				controle = false;
		}

		//Contrôle que les valeurs après le pivot soit plus grand
		for (auto k = vec.end(); k != i; --k) {
			if (*k < *i)
				controle = false;
		}

		cout << boolalpha << "Partition OK ? : " << controle << endl;
	}

	cout << endl;

	//Test Tri rapide
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
