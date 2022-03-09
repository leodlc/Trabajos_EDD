/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTORE: Leonardo de la Cadena
*TEMA: Prueba 2 parcial 1
* NRC: 7166
*FECHA: 29 DE NOVIEMBRE DEL 2021

* */
#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;
int procesoNumeroAll();
class Nodo {
private:
	int dato;
	Nodo* anterior;
	Nodo* siguiente;
public:
	Nodo(void);
	Nodo(int, Nodo*, Nodo*);
	//Constructor para lista simple
	Nodo(int _dato, Nodo* sig = NULL)
	{
		this->dato = _dato;
		this->siguiente = sig;
	}
	void setDato(int);
	int getDato(void);
	Nodo getSiguiente(void);
	void setSiguiente(Nodo*);
	Nodo getAnterior(void);
	void setAnterior(Nodo*);
	friend class Lista;

};

class Lista {
private:
	Nodo* cabeza;
	Nodo* cola;
public:
	Lista();
	bool vacio(void);
	void imprimir();
	int tamano();
	void eliminar(int);
	void insertarInicio(int);
	void insertarFinal(int);
	void insertarEntre(int, int);

	//int procesoNumeroAll(int);
};
class ListaSimple
{
private:
	Nodo* primero;
	Nodo* actual;
	int dimLista = 0;

public:
	ListaSimple()
	{
		this->primero = NULL;
		this->actual = NULL;
	}
	Nodo* obtenerNodo(int indice);
	bool listaVacia() { return (primero == NULL); };
	void insertar(int val);
	void insertarEn(int indice, int val);
	void eliminar(int indice);
	void mostrar();
	Nodo* getPrimero() { return primero; }
	void setPrimero(Nodo* pri) { primero = pri; }
	Nodo* getActual() { return actual; }
	void setActual(Nodo* act) { actual = act; }
	int getDimLista() { return dimLista; }
	void setDimLista(int dim) { dimLista = dim; }
	void mostrarRecursivo(Nodo* valor, int indice);
	int proceso();
};
void menu();
Lista::Lista() {
	cabeza = NULL;
	cola = NULL;
}

bool Lista::vacio(void) {
	if (cabeza == NULL && cola == NULL) {
		return true;
	}
	else {
		return false;
	}
}
//Funciones de la clase Lista Doble
void Lista::insertarInicio(int dato) {
	Nodo* tmp = new Nodo();
	tmp->dato = dato;
	tmp->siguiente = NULL;
	tmp->anterior = NULL;

	if (vacio() == true) {
		cabeza = tmp;
		cola = tmp;
	}
	else {
		tmp->siguiente = cabeza;
		cabeza->anterior = tmp;
		cabeza = tmp;
	}
}

void Lista::insertarFinal(int dato) {
	Nodo* tmp = new Nodo();
	tmp->dato = dato;
	tmp->siguiente = NULL;
	tmp->anterior = NULL;

	if (vacio() == true) {
		cabeza = tmp;
		cola = tmp;
	}
	else {
		cola->siguiente = tmp;
		tmp->anterior = cola;
		cola = tmp;
	}
}

void Lista::insertarEntre(int dato, int posicion) {
	Nodo* tmp = new Nodo();
	tmp->dato = dato;
	tmp->siguiente = NULL;
	tmp->anterior = NULL;

	if (vacio()) {
		cabeza = tmp;
		cola = tmp;
	}
	else {
		if (posicion == 1) {
			insertarInicio(dato);
		}
		else if (posicion == (tamano() + 1)) {
			insertarFinal(dato);
		}
		else if (posicion < 1 || posicion >= tamano()) {
			std::cout << "La lista no contine la posicion: " << posicion << " intentelo numavmente." << std::endl;
		}
		else if (posicion > 1 && posicion <= tamano()) {
			Nodo* aux;
			aux = cabeza;
			for (int i = 1; i < posicion; i++) {
				aux = aux->siguiente;
			}
			aux->anterior->siguiente = tmp;
			tmp->anterior = aux->anterior;
			tmp->siguiente = aux;
		}
	}
}

void Lista::imprimir() {
	Nodo* aux;
	aux = cabeza;
	int i = 0;
	while (aux != NULL) {
		cout << aux->dato << endl;
		aux = aux->siguiente;
		i++;
	}
}
int Lista::tamano() {
	int cont = 0;
	Nodo* aux;
	aux = cabeza;
	while (aux != NULL) {
		cont++;
		aux = aux->siguiente;
	}
	return cont;
}
void Lista::eliminar(int posicion) {
	Nodo* tmp = new Nodo();
	tmp->dato = 0;
	tmp->siguiente = NULL;
	tmp->anterior = NULL;

	if (vacio()) {
		cout << "No existe lista para eliminar." << endl;
	}
	else {
		if (posicion == 1) {
			cabeza = cabeza->siguiente;
		}
		else if (posicion == (tamano() + 1)) {
			cola->anterior->siguiente = nullptr;
		}
		else if (posicion < 1 || posicion >= tamano()) {
			std::cout << "La lista no contine la posicion: " << posicion << " intentelo numavmente." << std::endl;
		}
		else if (posicion > 1 && posicion <= tamano()) {
			Nodo* aux;
			aux = cabeza;
			for (int i = 1; i < posicion; i++) {
				aux = aux->siguiente;
			}
			aux->anterior->siguiente = aux->siguiente;
			aux->siguiente->anterior = aux->anterior;
		}
	}
}

//Fin de funciones de la clase Lista Doble
//Funciones clase Nodo
void Nodo::setDato(int newDato) {
	dato = newDato;
}

int Nodo::getDato(void) {
	return dato;
}

Nodo Nodo::getAnterior(void) {
	return *anterior;
}

void Nodo::setAnterior(Nodo* newAnterior) {
	anterior = newAnterior;
}

Nodo Nodo::getSiguiente(void) {
	return *siguiente;
}

void Nodo::setSiguiente(Nodo* newSiguiente) {
	siguiente = newSiguiente;
}

Nodo::Nodo() {
	dato = 0;
	siguiente = NULL;
	anterior = NULL;
}

Nodo::Nodo(int newDato, Nodo* newSiguiente, Nodo* newAnterior) {
	dato = newDato;
	siguiente = newSiguiente;
	anterior = newAnterior;
}
//Fin funciones clase Nodo


// Funcion generar numero aleatorio
int procesoNumeroAll() {
	int dato = 0;
	srand(time(NULL));
	dato = 100 + rand() % (99999 - 1);
	return dato;
}
//Funcion Menu
void menu() {
	cout << "==================LISTA DOBLE==========================="<<endl;
	cout << " 1. INSERTAR POR LA CABEZA               " << endl;
	cout << " 2. INSERTAR POR LA COLA                " << endl;
	cout << " 3. MOSTRAR LISTA                    " << endl;
	cout << " 4. INSERTAR ENTRE LA LISTA                  " << endl;
	cout << " 5. ELIMINAR ELEMENTO                " << endl;
	cout << " 6. SALIR                            " << endl;

	cout << "\n INGRESE OPCION: ";
}
int main()
{
    
	int opc, newDato;
	Lista list;
	do {
		system("cls");
		menu();
		cin >> opc;
		switch (opc) {
		case 1:
			
			newDato = procesoNumeroAll();
			list.insertarInicio(newDato);
			cout << "Se ingreso numero aleatorio en la cabeza de la lista" << endl;
			break;
		case 2:
			newDato = procesoNumeroAll();
			list.insertarFinal(newDato);
			cout << "Se ingreso numero aleatorio en la cola de la lista" << endl;
			break;
		case 3:
			list.imprimir();
			break;
		case 4:
			int pos;
			
			cout << "Ingrese la posicion: ";
			cin >> pos;
			newDato = procesoNumeroAll();
			list.insertarEntre(newDato, pos);
			cout << "Se ingreso numero aleatorio en la posicion: "<< pos << endl;
			break;
		case 5:
			cout << "Ingrese la posicion que quiere eliminar: ";
			cin >> pos;
			list.eliminar(pos);
			cout << "Se elimino la posicion: " << pos << endl;
			break;
		case 6:

			break;
		}
		system("pause");
	} while (opc != 6);

	return 0;
}


