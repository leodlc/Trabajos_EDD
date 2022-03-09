#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
template <typename tipoDato>
class AddElementos{
private:
	tipoDato numero1;
	tipoDato numero2;
	//tipoDato cadena1;
	//tipoDato cadena2;
public:
	AddElementos(tipoDato _numero1, tipoDato _numero2) {

		numero1 = _numero1;
		numero2 = _numero2;
		

	}
	

	tipoDato setNumero1(float _numero1) {

		numero1 = _numero1;
	}

	tipoDato setNumero2(float _numero2) {

		numero2 = _numero2;

	}

	tipoDato getNumero1() {

		return numero1;
	}

	tipoDato getNumero2() {

		return numero2;
	}
	

	tipoDato addNumeros();
	



};
template <typename tipoDato>
tipoDato AddElementos<tipoDato>::addNumeros() {
	return getNumero1() + getNumero2;

