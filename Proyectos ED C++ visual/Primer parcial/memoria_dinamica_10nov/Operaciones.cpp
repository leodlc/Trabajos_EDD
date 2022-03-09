/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORES: Cristian Maranje
*Leonardo de la Cadena
*Johnny Loachamin
*Alvaro Zumba
*TEMA: Manejo de memoria dinamica con templates
*FECHA DE CREACION : 10 DE NOVIEMBRE DEL 2021
*FECHA DE MODIFICACION: 11 DE NOVIEMBRE DE 2021
* */
#include "Operaciones.h"
using namespace std;
template <class T>
Operaciones<T>::Operaciones(T t) {
	this->p = (T*)malloc(4 * sizeof(T));
	this->t = t;
}
template <class T>
void Operaciones<T>::ingresar() {
	int i;
	for (i = 0; i < t; i++) {
		printf("Ingrese el valor entero: ");
		cin >> *(p + i);
		
	}
}
template <class T>
void Operaciones<T>::imprimir() {
	int i;
	for (i = 0; i < t; i++) {
		printf("\nValor ingresado: ");
		
		cout << *(p + i) << endl;
		
	}
}
template <class T>
void Operaciones<T>::procesar() {
	int i, e;
	T *_p= (T*)malloc(4 * sizeof(T));
	printf("\n Ingrese el escalar: ");
	cin >> e;
	
	for (i = 0; i < t; i++) {
		*(p + i) *= e;
		
		
	}
	
}
template class Operaciones<int>;
template class Operaciones<double>;
template class Operaciones<float>;