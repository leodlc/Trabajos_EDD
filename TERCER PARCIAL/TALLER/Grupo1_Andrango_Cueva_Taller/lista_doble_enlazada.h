/**************************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*TITULO: TALLER - MATRICULACION DE AUTOS
*AUTOR(ES): LUIS CUEVA, CHRISTIAN ANDRANGO
*FECHA: SABADO 26 DE FEBRERO DE 2022
*VERSION: 1
*ESTRUCTURA DE DATOS
*NRC: 7166
***************************************************************************/
#pragma once
#include "nodo.hpp"
#include <functional>
#include <iostream>

template<typename T>
class ListaDobleEnlazada {
public:
    // constructor por defecto
    ListaDobleEnlazada() = default;

    /*
     * Inserta un elemento al final de la lista
     */
    void insertar(T valor);

    /*
     * Inserta un elemento al inicio de la lista
     */
    void insertarInicio(T valor);

    /*
     * Inserta un elemento a la lista en un indice especifico,
     * una vez encontrado el indice, se puede especificar a que lado del elemento
     * encontrado se insertara el nuevo elemento (por defecto: derecha)
     */
    void insertarEn(int indice, T valor, Direccion = Direccion::Derecha);

    /*
     * Elimina un elemento de la lista dado un indice especifico
     */
    void eliminarEn(int indice);

    /*
     * Elimina los elementos de la lista que cumplan con el criterio
     * del parametro funcion 'filtro', si la funcion 'filtro' es una
     * funcion que retorna TRUE entonces el elemento es eliminado.
     */
    void eliminar(std::function<bool(T valor)> filtro);

    /*
     * Transforma todos los valores de la lista a un valor especifico
     * que devuelva la funcion anonima 'conversor'
     */
    void transformar(std::function<T(T valor)> conversor);

    /*
     * obtiene el ultimo nodo de la lista
     */
    Nodo<T>* obtenerUltimo();

    /*
     * obtiene un nodo de la lista en un indice especifico
     */
    Nodo<T>* obtenerEn(int indice);

    /*
     * Realiza una busqueda lineal en la lista, en cada iteracion
     * se llama al argumento 'filtro' el cual es una funcion anonima
     * en caso de que esta funcion regrese verdadero, entonces regresamos
     * el ultimo nodo recorrido, en caso de que nunca regrese verdadero,
     * se regresa un puntero nulo
     */
    Nodo<T>* buscar(std::function<bool(T valor)> filtro);

    /*
     * Recorre la lista elemento a elemento desde el inicio (cabeza)
     * cada iteración o ciclo ejecuta el argumento 'llamada', el cual
     * es una función anonima que recibe un parametro el cual es el
     * valor de cada nodo recorrido.
     */
    void recorrer(std::function<void(T valor)> llamada);

    /*
     * Regresa verdadero si tamanio_ tiene un valor de 0
     */
    bool vacio();

    /*
     * Retorna el tamaño de la lista
     */
    int tamanio();

    /* implementacion de iteradores: for mejorado */
	class Iterator {
		Nodo<T>* nodo_;

	public:
        Iterator(Nodo<T>* nodo) {
			nodo_ = nodo;
        }

        Nodo<T>* nodo() {
			return nodo_;
        }

		Iterator operator++() {
			nodo_ = nodo_->siguiente();
			return *this;
		}

		T operator*() {
			return nodo_->valor();
		}

		bool operator!=(const Iterator& rhs) {
			return !(this->nodo_ == rhs.nodo_);
		}
    };

	Iterator begin() {
		return Iterator(cabeza_);
	}

	Iterator end() {
		return Iterator(nullptr);
	}

private:
    Nodo<T>* cabeza_ = nullptr;
    int tamanio_ = 0;
};

template<typename T>
void ListaDobleEnlazada<T>::insertar(T valor)
{
    Nodo<T>* nodo = new Nodo<T>(valor);
    Nodo<T>* ultimo = obtenerUltimo();

    // si la cabeza es nula, la lista esta vacia
    // entonces definimos la cabeza como nuevo nodo
    if (cabeza_ == nullptr) {
        cabeza_ = nodo;
    }
    else {
        // agregamos el nodo a la lista enlazada
        ultimo->siguiente(nodo);
        nodo->anterior(ultimo);
    }

    // la lista agrego un elemento, incrementamos el tamaño
    tamanio_++;
}

template<typename T>
void ListaDobleEnlazada<T>::insertarInicio(T valor)
{
    Nodo<T>* nodo = new Nodo<T>(valor);

    // para insertar en el inicio, necesitamos la cabeza de la lista
    // si la lista esta vacia solo insertamos el elemento sin mas
    if (vacio()) {
        insertar(valor);
        return;
    }

    // creamos un temporal de la cabeza de la lista
    Nodo<T>* temporal = cabeza_;

    // el nuevo nodo apunta a la cabeza
    nodo->siguiente(cabeza_);
    cabeza_->anterior(nodo);

    // ahora el nuevo nodo es la cabeza
    cabeza_ = nodo;
}

template<typename T>
void ListaDobleEnlazada<T>::insertarEn(int indice, T valor, Direccion direccion)
{
    // verificamos que el indice exista
    if (indice < 0 || indice >= tamanio_) {
        std::cerr
            << "ERROR: indice fuera de los limites [" << indice << "]"
            << std::endl;

        return;
    }

    // si existe un solo elemento en la lista la insercion es 
    // al inicio o al final (izquierda o derecha)
    if (tamanio_ == 1) {
        if (direccion == Direccion::Izquierda) {
            insertarInicio(valor);
        }
        else {
            insertar(valor);
        }

        // si el indice es 0 y la insercion es hacia la izquierda,
        // entonces insertamos al inicio
    }
    else if (indice == 0 && direccion == Direccion::Izquierda) {
        insertarInicio(valor);

        // si el indice es el ultimo elemento y la insercion es 
        // hacia a la derecha, entonces solo insertamos al final
    }
    else if (indice == tamanio_ - 1 && direccion == Direccion::Derecha) {
        insertar(valor);

        // insertamos en el indice deseado en la direccion deseada
    }
    else {
        Nodo<T>* objetivo = obtenerEn(indice);
        Nodo<T>* anterior = objetivo->anterior();
        Nodo<T>* siguiente = objetivo->siguiente();
        Nodo<T>* nodo = new Nodo<T>(valor);

        if (direccion == Direccion::Derecha) {
            objetivo->siguiente(nodo);
            nodo->anterior(objetivo);
            nodo->siguiente(siguiente);
            siguiente->anterior(nodo);
        }
        else {
            anterior->siguiente(nodo);
            nodo->anterior(anterior);
            nodo->siguiente(objetivo);
            objetivo->anterior(nodo);
        }

        tamanio_++;
    }
}

template<typename T>
void ListaDobleEnlazada<T>::eliminarEn(int indice)
{
    // verificamos que el indice exista
    if (indice < 0 || indice >= tamanio_) {
        std::cerr
            << "ERROR: indice fuera de los limites [" << indice << "]"
            << std::endl;

        return;
    }

    // si el indice es 0 o el tamaño es 1...
    if (indice == 0 || tamanio_ == 1) {
        // si el tamaño es superior a 1 entonces eliminamos
        // la cabeza y asignamos como cabeza al siguiente nodo
        if (tamanio_ > 1) {
            Nodo<T>* temporal = cabeza_;
            cabeza_ = cabeza_->siguiente();
            cabeza_->anterior(nullptr);
            delete temporal;
        } else { // si el tamaño es 1 entonces es la cabeza
            delete cabeza_;
            cabeza_ = nullptr;
        }
    } else if (indice == tamanio_ - 1) {
        Nodo<T>* objetivo = obtenerEn(indice);
        Nodo<T>* penultimo = objetivo->anterior();

        delete objetivo;
        penultimo->siguiente(nullptr);
    } else {
        Nodo<T>* objetivo = obtenerEn(indice);
        Nodo<T>* anterior = objetivo->anterior();
        Nodo<T>* siguiente = objetivo->siguiente();

        delete objetivo;
        anterior->siguiente(siguiente);
        siguiente->anterior(anterior);
    }

    tamanio_--;
}

template<typename T>
void ListaDobleEnlazada<T>::eliminar(std::function<bool(T valor)> filtro)
{
    Nodo<T>* nodo = cabeza_;
    int indice = 0;

    // recorremos toda la lista
    while (nodo != nullptr) {
        // verificamos si la funcion 'filtro' devuelve TRUE o FALSE
        bool eliminar = filtro(nodo->valor());

        // si devuelve FALSE entonces eliminamos el elemento por el indice
        // y cerramos el bucle con 'return'
        if (eliminar) {
            eliminarEn(indice);
            return;
        }

        nodo = nodo->siguiente();
        indice++;
    }
}

template<typename T>
inline void ListaDobleEnlazada<T>::transformar(std::function<T(T valor)> conversor)
{
    Nodo<T>* nodo = cabeza_;

    while (nodo != nullptr) {
        T nuevoValor = conversor(nodo->valor());
        nodo->valor(nuevoValor);
        nodo = nodo->siguiente();
    }
}

template<typename T>
Nodo<T>* ListaDobleEnlazada<T>::obtenerUltimo()
{
    Nodo<T>* ultimo = cabeza_;

    if (ultimo == nullptr) {
        return nullptr;
    }

    // recorremos todos los nodos hasta llegar al ultimo
    while (ultimo != nullptr && ultimo->siguiente() != nullptr) {
        ultimo = ultimo->siguiente();
    }

    // retornamos el ultimo nodo encontrado
    return ultimo;
}

template<typename T>
Nodo<T>* ListaDobleEnlazada<T>::obtenerEn(int indice)
{
    // verificamos que el indice exista en la lista
    if (indice < 0 || indice >= tamanio_) {
        std::cerr
            << "ERROR: indice fuera de los limites [" << indice << "]"
            << std::endl;
        return nullptr;
    }

    int i = 0; // indice
    Nodo<T>* nodo = cabeza_; // primer elemento

    // recorremos la lista entera hasta encontrar el elemento
    // que tenga el indice deseado
    while (nodo != nullptr) {
        if (i++ == indice) {
            return nodo;
        }

        nodo = nodo->siguiente();
    }

    return nullptr;
}

template<typename T>
Nodo<T>* ListaDobleEnlazada<T>::buscar(std::function<bool(T valor)> filtro)
{
    // recorremos toda la lista nodo a nodo, cuando la funcion 'filtro'
    // devuelva TRUE entonces habremos encontrado el elemento, devolvemos
    // ese nodo encontrado
    for (Nodo<T>* nodo = cabeza_; nodo != nullptr; nodo = nodo->siguiente()) {
        bool encontrado = filtro(nodo->valor());

        if (encontrado) {
            return nodo;
        }
    }

    return nullptr;
}

template<typename T>
void ListaDobleEnlazada<T>::recorrer(std::function<void(T valor)> llamada)
{
    // recorremos la lista nodo a nodo, en cada ciclo se llama a la funcion
    // 'llamada' y le pasamos el valor de cada nodo
    for (Nodo<T>* nodo = cabeza_; nodo != nullptr; nodo = nodo->siguiente()) {
        llamada(nodo->valor());
    }
}

template<typename T>
bool ListaDobleEnlazada<T>::vacio()
{
    return tamanio_ == 0;
}

template<typename T>
int ListaDobleEnlazada<T>::tamanio()
{
    return tamanio_;;
}
