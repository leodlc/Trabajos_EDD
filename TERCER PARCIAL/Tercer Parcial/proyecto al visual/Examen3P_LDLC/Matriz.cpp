#include "Matriz.h"
#include <time.h>
#include <iostream>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

using namespace std;



Matriz::Matriz(int _dimension)
{
	this->d = _dimension;
}

Matriz::Matriz()
{

}


void Matriz::setDimension(int _dimension)
{
	this->d = _dimension;
}


void Matriz::setMatriz(int** matri)
{
	this->mat = matri;
}


int Matriz::getDimension()
{
	return d;
}


int** Matriz::getMatriz()
{
	return mat;
}
////@brief Reserva memoria para la matriz
////*

void Matriz::segmentar()
{
	mat = (int**)malloc(d * sizeof(int*));
	for (int j = 0; j < d; j++)
		*(mat + j) = (int*)malloc(d * sizeof(int));
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

void Matriz::encerar()
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


void Matriz::ingresar()
{
	int dato;
	srand(time(NULL));
	for (int i = 0; i < d; i++)
		for (int j = 0; j < d; j++) {
			
			dato = 10000 + rand() % (99999 - 10000);
			
			*(*(mat + i) + j) = dato;
			//pasando a binario
			//buscarBinario(dato);
		}

}
//**
// * @brief Impresion de la matriz
// */

void Matriz::imprimir()
{
	for (int i = 0; i < d; i++) {
		for (int j = 0; j < d; j++)
		{
			cout <<  * (*(mat + i) + j);
			printf("%*s", j + 5, "");
			//cout << "Matriz a binarios" << endl;
			/*cout << buscarBinario(*(*(mat + i) + j));
			printf("%*s", j + 5, "");*/
		}
		printf("\n");
	}
}

int Matriz::buscarBinario(int numero_decimal)
{
	if (numero_decimal == 0)
		return 0;
	else
		return (numero_decimal % 2 + 10 *
			buscarBinario(numero_decimal / 2));
}
//void Matriz::imprimirBinario() {
//	/*Matriz matrizBinaria;
//	matrizBinaria.segmentar();
//	int** res = matrizBinaria.getMatriz();
//	int** mtemp = matrizTemp.getMatriz();*/
//
//}
//	 * @brief  Multiplicacion de Matrices
//	 */
//template<class T>
//Matriz<T> Matriz<T>::procesar(Matriz<T> matrizTmp)
//{
//	Matriz<T> mr(d);
//	mr.segmentar();
//	T** res = mr.getMatriz();
//	T** mtemp = matrizTmp.getMatriz();
//	for (int i = 0; i < d; i++) {
//		for (int j = 0; j < d; j++) {
//			for (int h = 0; h < d; h++) {
//				*(*(res + i) + j) = *(*(res + i) + j) + (*(*(mat + i) + h)) * (*(*(mtemp + h) + j));
//			}
//		}
//	}
//	return mr;
//}
