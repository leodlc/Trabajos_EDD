/***********************************************************************
 * Module:  Producto.cpp
 * Author:  AsrockLeo
 * Modified: viernes, 29 de octubre de 2021 19:19:25
 * Purpose: Implementation of the class Producto
 ***********************************************************************/

#include "Producto.h"
using namespace std;
template <typename T>
T Producto<T>::obtenerPrecioFinal() {
	cout << "El precio final del producto es: ";
	return getValorInicial() + getValorInicial() * getIva() / 100;




}
 ////////////////////////////////////////////////////////////////////////
 // Name:       Producto::Producto()
 // Purpose:    Implementation of Producto::Producto()
 // Return:     
 ////////////////////////////////////////////////////////////////////////

//Producto::Producto()
//{
//}

////////////////////////////////////////////////////////////////////////
// Name:       Producto::~Producto()
// Purpose:    Implementation of Producto::~Producto()
// Return:     
////////////////////////////////////////////////////////////////////////

//Producto::~Producto()
//{
//	// TODO : implement
//}

////////////////////////////////////////////////////////////////////////
// Name:       Producto::getIva()
// Purpose:    Implementation of Producto::getIva()
// Return:     float
////////////////////////////////////////////////////////////////////////
//
//T Producto<T>::getIva()const
//{
//
//	return this->iva;
//}
//
//////////////////////////////////////////////////////////////////////////
//// Name:       Producto::setIva(float newIva)
//// Purpose:    Implementation of Producto::setIva()
//// Parameters:
//// - newIva
//// Return:     void
//////////////////////////////////////////////////////////////////////////
//template <typename T>
//void Producto<T>::setIva(T newIva)
//{
//
//	this->iva = newIva;
//}
//
//////////////////////////////////////////////////////////////////////////
//// Name:       Producto::getValorInicial()
//// Purpose:    Implementation of Producto::getValorInicial()
//// Return:     float
//////////////////////////////////////////////////////////////////////////
//template <typename T>
//T Producto<T>::getValorInicial()const
//{
//	return this-> valorInicial;
//}
//
//////////////////////////////////////////////////////////////////////////
//// Name:       Producto::setValorInicial(float newValorInicial)
//// Purpose:    Implementation of Producto::setValorInicial()
//// Parameters:
//// - newValorInicial
//// Return:     void
//////////////////////////////////////////////////////////////////////////
//template <typename T>
//void Producto<T>::setValorInicial(T newValorInicial)
//{
//	this->valorInicial = newValorInicial;
//}
//
//////////////////////////////////////////////////////////////////////////
//// Name:       Producto::getPrecio()
//// Purpose:    Implementation of Producto::getPrecio()
//// Return:     float
//////////////////////////////////////////////////////////////////////////
//template <typename T>
//T Producto<T>::getPrecio()const
//{
//	return this->precio;
//}
//
//////////////////////////////////////////////////////////////////////////
//// Name:       Producto::setPrecio(float newPrecio)
//// Purpose:    Implementation of Producto::setPrecio()
//// Parameters:
//// - newPrecio
//// Return:     void
//////////////////////////////////////////////////////////////////////////
//template <typename T>
//void Producto<T>::setPrecio(T newPrecio)
//{
//	this->precio = newPrecio;
//}
//
//////////////////////////////////////////////////////////////////////////
//// Name:       Producto::getNombre()
//// Purpose:    Implementation of Producto::getNombre()
//// Return:     std::string
//////////////////////////////////////////////////////////////////////////
//template <typename T>
//T Producto<T>::getNombre()const
//{
//	return this->nombre;
//}
//
//////////////////////////////////////////////////////////////////////////
//// Name:       Producto::setNombre(std::string newNombre)
//// Purpose:    Implementation of Producto::setNombre()
//// Parameters:
//// - newNombre
//// Return:     void
//////////////////////////////////////////////////////////////////////////
//template <typename T>
//void Producto<T>::setNombre(T newNombre)
//{
//	this->nombre = newNombre;
//}
//
//////////////////////////////////////////////////////////////////////////
//// Name:       Producto::calularPrecio(float precioNormal, float valorIva, float precioFinal)
//// Purpose:    Implementation of Producto::calularPrecio()
//// Parameters:
//// - precioNormal
//// - valorIva
//// - precioFinal
//// Return:     void
//////////////////////////////////////////////////////////////////////////
//template <typename T>
//float Producto<T>::calcularPrecio(T precioNormal, T valorIva, T* precioFinal)
//{
//	float tempPrecioNormal;
//	
//	/*T precioTempNor = precioNormal;
//	Producto<float> precioNormal;*/
//	
//	/*Producto<float> tempPrecioNormal;
//	tempPrecioNormal = T precionormal;
//	precioNormal.*/
//	
//	
//	
//	
//	
//	
//
//}
//
//////////////////////////////////////////////////////////////////////////
//// Name:       Producto::imprimirPrecio()
//// Purpose:    Implementation of Producto::imprimirPrecio()
//// Return:     void
//////////////////////////////////////////////////////////////////////////
//template <typename T>
//void Producto<T>::imprimirPrecio()const
//{
//	
//}