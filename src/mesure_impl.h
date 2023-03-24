//
// Created by Dario Vasques on 24.03.23.
//

#ifndef ASD_LABOS_2021_MESURE_IMPL_H
#define ASD_LABOS_2021_MESURE_IMPL_H

#include <chrono>
#include <iostream>

template<typename T, typename Fn>
double mesure_temps(std::vector<T>& v1, Fn f) {
   //Temps avant tri
   auto t1 = std::chrono::high_resolution_clock::now();
   //Tri
   f(v1.begin(), v1.end() - 1);
   //Temps après tri
   auto t2 = std::chrono::high_resolution_clock::now();
   //Différence entre les deux temps
   std::chrono::duration<double, std::milli> time_ms = t2 - t1;

   //Test si le vecteur est bien trié
   std::cout << std::boolalpha << std::is_sorted(v1.begin(), v1.end()) << std::endl;

   return (double)time_ms.count();
}

#endif //ASD_LABOS_2021_MESURE_IMPL_H
