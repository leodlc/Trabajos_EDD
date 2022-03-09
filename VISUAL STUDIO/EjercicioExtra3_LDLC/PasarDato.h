#pragma once
#include <iostream>
#include <conio.h>
using namespace std;
template <typename PLANT>
class PasarDato{
private:
	PLANT dato;
public:
	PasarDato(PLANT _dato) {
		dato = _dato;


	}
	void pasarDato(PLANT _dato) {
		cout << "El dato es: " << _dato << endl;
		
	}

};

//template <typename PLANT>
//PLANT pasarDato(PLANT dato) {
//	cout << "El dato es: " << dato << endl;
//}

