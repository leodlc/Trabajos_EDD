#pragma once
//#if !defined(__Class_Diagram_2_Producto_h)
//#define __Class_Diagram_2_Producto_h
#include <iostream>
#include <stdio.h>

using namespace std;
template <typename T>

class Producto {
private:
	T valorInicial;
	T valorIva;
	
public:

	Producto(T _valorInicial, T _valorIva) {

		valorInicial = _valorInicial;
		valorIva = _valorIva;
	}

	T setValorInicial(float _valorInicial) {

		valorInicial = _valorInicial;
	}

	T setValorIva(float _valorIva) {

		valorIva = _valorIva;

	}


	T getValorInicial() {

		return valorInicial;
	}

	T getValorIva() {

		return valorIva;
	}

	T calc();

};

template <typename T>
T Producto<T>::calc() {
	
	return getValorInicial() + getValorInicial() * getValorIva() / 100;
}
