#include "Matriz.h"
#include <time.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;

template <class T>
Matriz<T>::Matriz(T _dimension)
{
	this->d = _dimension;
}
template <class T>
Matriz<T>::Matriz()
{

}

template <class T>
void Matriz<T>::setDimension(T _dimension)
{
	this->d = _dimension;
}

template <class T>
void Matriz<T>::setMatriz(T** matri)
{
	this->mat = matri;
}

template <class T>
T Matriz<T>::getDimension()
{
	return d;
}

template <class T>
T** Matriz<T>::getMatriz()
{
	return mat;
}
////@brief Reserva memoria para la matriz
////*
template <class T>
void Matriz<T>::segmentar()
{
	mat = (T**)malloc(d * sizeof(T*));
	for (int j = 0; j < d; j++)
		*(mat + j) = (T*)malloc(d * sizeof(T));
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			*(*(mat + i) + j) = 0;
		}
	}
}
///**
//	 * @brief Inicializa la matriz en cero
//	 *
//	 */
template <class T>
void Matriz<T>::encerar()
{
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			*(*(mat + i) + j) = 0;
		}
	}
	return;
}

///**
//	 * @brief Asigna Valores a la matriz

template <class T>
void Matriz<T>::ingresar()
{
	T dato;
	srand(time(NULL));
	for (int i = 0; i < d; i++)
		for (int j = 0; j < d; j++) {
			//cout << "Ingrese el numero de [" << i + 1 << "][" << j + 1 << "]: ";
			dato = 10000 + rand() % (99999 - 10000);
			//cin >> dato;
			*(*(mat + i) + j) = dato;
		}

}
//**
// * @brief Impresion de la matriz
// */
template <class T>
void Matriz<T>::imprimir()
{
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++)
		{
			cout << *(*(mat + i) + j);
			printf("%*s", j + 5, "");
		}
		printf("\n");
	}
}
//	 * @brief  Multiplicacion de Matrices
//	 */
template<class T>
Matriz<T> Matriz<T>::procesar(Matriz<T> matrizTmp)
{
	Matriz<T> mr(d);
	mr.segmentar();
	T** res = mr.getMatriz();
	T** mtemp = matrizTmp.getMatriz();
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++) {
			for (int h = 0; h < d; h++) {
				*(*(res + i) + j) = *(*(res + i) + j) + (*(*(mat + i) + h)) * (*(*(mtemp + h) + j));
			}
		}
	}
	return mr;
}

template class Matriz<int>;
template class Matriz<float>;
template class Matriz<double>;