/**************************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*TITULO: DEBER 1 - EJERCICIOS COLAS
*AUTOR(ES): LUIS CUEVA, CHRISTIAN ANDRANGO, ARIEL JARA. JORGE PAUCAR, JORGE AGUAS
*FECHA: JUEVES 11 DE DICIEMBRE DE 2021
*VERSION: 1
*ESTRUCTURA DE DATOS
*NRC: 7166
***************************************************************************/
#pragma once
template <class T>
class Nodo
{
private:
	Nodo* siguiente;
	T dato;
public:
	Nodo();
	~Nodo();
	void establecer_dato(T);
	T obtener_dato(void);
	Nodo* obtener_siguiente(void);
	void establecer_siguiente(Nodo*);
};
template < class T>
Nodo<T>::Nodo() {
	siguiente = NULL;
	dato = 0;
}
template <class T>
void Nodo<T>::establecer_dato(T value) {
	dato = value;
}
template <class T>
T Nodo<T>::obtener_dato() {
	return dato;
}
template <class T>
void Nodo<T>::establecer_siguiente(Nodo* item) {
	siguiente = item;
}
template <class T>
Nodo<T>* Nodo<T>::obtener_siguiente() {
	return siguiente;
}
