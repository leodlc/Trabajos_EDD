/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES: Cristian Maranje
*Leonardo de la Cadena
*Johnny Loachamin
*Alvaro Zumba
*TEMA: Cola de banco
*FECHA DE CREACION : 12 DE DICIEMBRE DEL 2021
*FECHA DE MODIFICACION: 13 DE DICIEMBRE DE 2021
* */
#pragma once
#include "Nodo.h"
#include <iostream>
#include <stdlib.h>
using namespace std;
using namespace std;

template <class T>
class Cola
{
private:
	Nodo<T>* cabeza, * cola;
	int tam;
public:
	Cola();
	~Cola();
	void encolar(int);
	int desencolar(void);
	int tamanio(void);
	void mostrar(void);
	bool estaVacia(void);
};
template <class T>
Cola<T>::Cola() {
	cabeza = cola = NULL;
	tam = 0;
}
template <class T>
void Cola<T>::encolar(int valor) {
	for (int i = 1; i <= valor; i++) {
		Nodo<T>* nuevo_nodo = new Nodo<T>();
		nuevo_nodo->establecerDato(i);
		if (cabeza == NULL) {
			cabeza = nuevo_nodo;
			cola = nuevo_nodo;
			nuevo_nodo->establecerSiguiente(NULL);
			tam++;
		}
		else {
			cola->establecerSiguiente(nuevo_nodo);
			nuevo_nodo->establecerSiguiente(NULL);
			cola = nuevo_nodo;
			tam++;
		}
	}

}
template <class T>
int Cola<T>::desencolar() {
	int valor = -1;
	if (cabeza == NULL)
		return -1;
	else {
		valor = cabeza->obtenerDato();
		cabeza = cabeza->obtenerSiguiente();
		tam--;
	}
	return valor;
}
template <class T>
int Cola<T>::tamanio() {
	return tam;
}
template <class T>
bool Cola<T>::estaVacia() {
	if (cabeza == NULL)
		return true;
	else
		return false;
}
template <class T>
void Cola<T>::mostrar() {
	int tiempoLLegada[100]{};
	int tiempoSalida[100]{};
	int tiempoServicio[100]{};
	int tiempoEspera[100]{};
	int tiempoNoCajero[100]{};
	int tLLegada = 1;
	int tEspera = 1;
	int tSalida = 1;
	int tServicio = 1;
	int tEntreLLegada = 1;
	int tNoCajero = 1;
	if (cabeza == NULL)
		cout << "NO HAY DATOS";
	else {
		for (Nodo<int>* recorrer = cabeza; recorrer != NULL; recorrer = recorrer->obtenerSiguiente()) {
			//Generamos el tiempo de llegada
			for (int i = 1; i < recorrer->obtenerDato(); i++)
			{
				tiempoLLegada[i] = rand() % 51;
				tLLegada = tiempoLLegada[i];

				//Generamos el tiempo entrellegada
				tEntreLLegada = tiempoLLegada[i] - tiempoLLegada[i - 1];
			}
			//Generamos el tiempo de espera
			for (int i = 1; i < recorrer->obtenerDato(); i++)
			{
				tiempoEspera[i] = 1 + rand() % (11 - 1);
				tEspera = tiempoEspera[i];

			}
			//Genera el tiempo de servicio
			for (int i = 1; i < recorrer->obtenerDato(); i++)
			{
				tiempoServicio[i] = 1 + rand() % (6 - 1);
				tServicio = tiempoServicio[i];

			}

			//Genera tiempo de salida
			for (int i = 1; i < recorrer->obtenerDato(); i++)
			{
				tSalida = tiempoLLegada[i] + tiempoEspera[i] + tiempoServicio[i];
				tiempoLLegada[i] = tSalida;
			}

			//Genera tiempo de trabajo del cajero
			for (int i = 1; i < recorrer->obtenerDato(); i++)
			{
				if (i > 1) {
					if (tiempoLLegada[i + 1] > tiempoSalida[i]) {
						tNoCajero = tiempoLLegada[i + 1] - tiempoSalida[i];
					}
					else {
						tNoCajero = tiempoSalida[i] - tiempoSalida[i];
					}
				}


			}

			cout << "Cliente" << recorrer->obtenerDato() << " ,Tiempo de llegada: " << tLLegada << endl;;
			cout << " Tiempo de espera: " << tEspera<<endl;
			cout << " Tiempo entre llegada: " << tEntreLLegada<<endl;
			cout << " Tiempo de no trabaja cajero: " << tNoCajero<<endl;
			cout << " Tiempo de servicio: " << tServicio<<endl;
			cout << " Tiempo de salida: " << tSalida<<endl;
			cout << "\n";
			
		}
	}
}
