/**************************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*TITULO: EXPOSICION - SHELLSORT
*AUTOR(ES): LUIS CUEVA, CHRISTIAN ANDRANGO, ARIEL JARA. JORGE PAUCAR, JORGE AGUAS, CRISTOFER ZAMBRANO
*FECHA: MIERCOLES 22 DE DICIEMBRE DE 2021
*VERSION: 1
*ESTRUCTURA DE DATOS
*NRC: 7166
***************************************************************************/
#pragma once
#include <stdio.h>
#include <windows.h>
#include <iostream>
#include <functional>
#include <type_traits>
#include <algorithm>
#include <cmath>

namespace Shellsort {
    int vector[100], temp, inc, i, j;

    //funcion lambda shellsort
    void shellsort(int V[], int N) {

            for (inc = 1; inc < N; inc = inc * 3 + 1);
            while (inc > 0) {
                for (i = inc; i < N; i++) {
                    j = i;
                    temp = V[i];
                    while ((j >= inc) && (V[j - inc] > temp)) {
                        V[j] = V[j - inc];
                        j = j - inc;
                    }
                    V[j] = temp;
                }
                inc /= 2;
            }
    }

    void mostrar(int V[], int N) {
        for (int i = 0; i < N; i++) {
            std::cout << V[i] << " ";
        }
    }

};

//using namespace std;
//
//template <class T>
//class Shellsort {
//	public:
//		int vector[100], temp, inc, i, j;
//		void shellSort(int[], int);
//		
//		void mostrar(int[], int);
//		//auto Shellsort = [&](int[], int)
//};
//
////template <class T>
////auto Shellsort = [&](int V[], int N) -> int {
////	for (inc = 1; inc < N; inc = inc * 3 + 1);
////	while (inc > 0) {
////		for (i = inc; i < N; i++) {
////			j = i;
////			temp = V[i];
////			while ((j >= inc) && (V[j - inc] > temp)) {
////				V[j] = V[j - inc];
////				j = j - inc;
////			}
////			V[j] = temp;
////		}
////		inc /= 2;
////	}
////	return inc;
////}
//
//void Shellsort::shellSort(int V[],int N) {
//	for (inc = 1; inc < N; inc = inc * 3 + 1);
//	while (inc > 0) {
//		for (i = inc; i < N; i++) {
//			j = i;
//			temp = V[i];
//			while ((j >= inc) && (V[j - inc] > temp)) {
//				V[j] = V[j - inc];
//				j = j - inc;
//			}
//			V[j] = temp;
//		}
//		inc /= 2;
//	}
//}
//
//
//void Shellsort::mostrar(int V[], int N) {
//	for (int i = 0; i < N; i++) {
//		cout << V[i] << " ";
//	}
//
//}