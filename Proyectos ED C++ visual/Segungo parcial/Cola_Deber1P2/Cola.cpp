/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES: Cristian Maranje
*Leonardo de la Cadena
*Johnny Loachamin
*Alvaro Zumba
*TEMA: Cola de banco
*FECHA DE CREACION : 12 DE DICIEMBRE DEL 2021
*FECHA DE MODIFICACION: 13 DE CICIEMBRE DE 2021
* */
//#include "Cola.h"
//#include <iostream>
//#include <stdlib.h>
//using namespace std;
//template <class T>
//Cola<T>::Cola() {
//	cabeza = cola = NULL;
//	tam = 0;
//}
//template <class T>
//void Cola<T>::encolar(int valor) {
//	for (int i = 1; i <= valor; i++) {
//		Nodo<T>* nuevo_nodo = new Nodo<T>();
//		nuevo_nodo->establecer_dato(i);
//		if (cabeza == NULL) {
//			cabeza = nuevo_nodo;
//			cola = nuevo_nodo;
//			nuevo_nodo->establecer_siguiente(NULL);
//			tam++;
//		}
//		else {
//			cola->establecer_siguiente(nuevo_nodo);
//			nuevo_nodo->establecer_siguiente(NULL);
//			cola = nuevo_nodo;
//			tam++;
//		}
//	}
//
//}
//template <class T>
//int Cola<T>::desencolar() {
//	int valor = -1;
//	if (cabeza == NULL)
//		return -1;
//	else {
//		valor = cabeza->obtener_dato();
//		cabeza = cabeza->obtener_siguiente();
//		tam--;
//	}
//	return valor;
//}
//template <class T>
//int Cola<T>::tamanio() {
//	return tam;
//}
//template <class T>
//bool Cola<T>::estaVacia() {
//	if (cabeza == NULL)
//		return true;
//	else
//		return false;
//}
//template <class T>
//void Cola<T>::mostrar() {
//	int tiempoLLegada[100]{};
//	int tiempoSalida[100]{};
//	int tiempoServicio[100]{};
//	int tiempoEspera[100]{};
//	int tiempoNoCajero[100]{};
//	int tLLegada = 1;
//	int tEspera = 1;
//	int tSalida = 1;
//	int tServicio = 1;
//	int tEntreLLegada = 1;
//	int tNoCajero = 1;
//	if (cabeza == NULL)
//		cout << "NO HAY DATOS";
//	else {
//		for (Nodo<int>* recorrer = cabeza; recorrer != NULL; recorrer = recorrer->obtener_siguiente()) {
//			//GENERAR TIEMPO DE LLEGADA
//			for (int i = 1; i < recorrer->obtener_dato(); i++)
//			{
//				tiempoLLegada[i] = rand() % 51;
//				tLLegada = tiempoLLegada[i];
//
//				//GENERAR TIEMPO ENTRE LLEGADAS
//				tEntreLLegada = tiempoLLegada[i] - tiempoLLegada[i - 1];
//			}
//			//GENERAR TIEMPO DE ESPERA
//			for (int i = 1; i < recorrer->obtener_dato(); i++)
//			{
//				tiempoEspera[i] = 1 + rand() % (11 - 1);
//				tEspera = tiempoEspera[i];
//
//			}
//			//GENERAR TIEMPO DE SERVICIO
//			for (int i = 1; i < recorrer->obtener_dato(); i++)
//			{
//				tiempoServicio[i] = 1 + rand() % (6 - 1);
//				tServicio = tiempoServicio[i];
//
//			}
//
//			//GENERAR TIEMPO DE SALIDA
//			for (int i = 1; i < recorrer->obtener_dato(); i++)
//			{
//				tSalida = tiempoLLegada[i] + tiempoEspera[i] + tiempoServicio[i];
//				tiempoLLegada[i] = tSalida;
//			}
//
//			//GENERAR TIEMPO DE TRABAJAR CAJERO
//			for (int i = 1; i < recorrer->obtener_dato(); i++)
//			{
//				if (i > 1) {
//					if (tiempoLLegada[i + 1] > tiempoSalida[i]) {
//						tNoCajero = tiempoLLegada[i + 1] - tiempoSalida[i];
//					}
//					else {
//						tNoCajero = tiempoSalida[i] - tiempoSalida[i];
//					}
//				}
//
//
//			}
//
//			cout << "\nCliente" << recorrer->obtener_dato() << " ,Tiempo de llegada: " << tLLegada;
//			cout << " ,Tiempo de espera: " << tEspera;
//			cout << " ,Tiempo entre llegada: " << tEntreLLegada;
//			cout << " ,Tiempo de no trabaja cajero: " << tNoCajero;
//			cout << " ,Tiempo de servicio: " << tServicio;
//			cout << " ,Tiempo de salida: " << tSalida;
//			cout << "\n";
//			/*" ,Tiempo de Espera: " << tEspera <<
//			" ,Tiempo de no trabaja cajero: " << tNoCajero << " ,Tiempo de servicio: " << tServicio<< " ,Tiempo de salida: " << tSalida << " ,Tiempo entre llegada: " << tEntreLLegada << "\n";*/
//		}
//	}
//}
