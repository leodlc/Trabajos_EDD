#pragma once
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <string>
using namespace std;
template <typename tipoDato>
class AñadirElementos{
private:
	tipoDato numero1;
	tipoDato numero2;
	tipoDato cadena1;
	tipoDato cadena2;
public:
	AñadirElementos(tipoDato _numero1, tipoDato _numero2, tipoDato _cadena1, tipoDato _cadena2) {

		numero1 = _numero1;
		numero2 = _numero2;
		cadena1 = _cadena1;
		cadena2 = _cadena2;

	}

	tipoDato setNumero1(int _numero1) {

		numero1 = _numero1;
	}

	tipoDato setNumero2(float _numero2) {

		numero2 = _numero2;

	}
	tipoDato setCadena1(string _cadena1) {

		cadena1 = _cadena1;
	}

	tipoDato setCadena2(string _cadena2) {

		cadena2 = _cadena2;

	}



	tipoDato getNumero1() {

		return numero1;
	}

	tipoDato getNumero2() {

		return numero2;
	}
	tipoDato getCadena1() {

		return cadena1;
	}

	tipoDato getCadena2() {

		return cadena2;
	}

	tipoDato añadirNumeros();
	tipoDato concatenar();



};

