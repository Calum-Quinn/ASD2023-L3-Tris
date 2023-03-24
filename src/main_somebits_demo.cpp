#include <iostream>
#include <limits>
#include "some_bits.h"
#include <vector>
#include "tri_rapide.h"
#include "tri_par_base.h"

using namespace std;
using ui = unsigned int;

int main() {

//    ui n; cin >> n;
//
//    for(unsigned nbits : { 1u, 2u, 4u, 8u, 16u }) {
//        cout << nbits << " : ";
//        for (unsigned i = 0; i < numeric_limits<ui>::digits / nbits ; ++i ) {
//            auto fn = SomeBits<unsigned long long>(nbits, i);
//            cout << fn(n) << " ";
//        }
//        cout << endl;
//    }

    vector<int> v = {1 ,3, 4, 2, 9, 5, 11, 8, 6, 7};

    for(int i : v){
        cout << i << " ";
    }
    cout << endl;

    tri_rapide<vector<int>::iterator>(v.begin(), v.end() -1);
    //tri_rapide<vector<int>::iterator,cle>(v.begin(), v.end() -1);

   for(int i : v){
        cout << i << " ";
    }
    cout << endl << endl;





    vector<unsigned> vec = {93, 45, 23, 76, 34, 0, 110, 67, 54};
    tri_par_base<vector<unsigned>::iterator,2>(vec.begin(),vec.end() - 1);

    for (unsigned i : vec) {
        cout << i << " ";
    }




    return 0;
}

