#include "LatinSquare.h"
using namespace std;
//template <class T>
LatinSquare::LatinSquare() {

}
//template <class T>
int LatinSquare::getDimension() {
	return this->dimension;
}
 //template <class T>
int LatinSquare::getI() {
	return this->i;
}
//template <class T>
int LatinSquare::getJ() {
	return this->j;
}
//template <class T>
int LatinSquare::getK() {
	return this->k;
}
//template <class T>
int LatinSquare::getM() {
	return this->m;
}
//template <class T>
int LatinSquare::getP() {
	return this->p;
}
//template <class T>
void LatinSquare::obtainSquare(int dimension) {
	//getK() = dimension;
	
	getP() = 0;
	getM() = 0;
	for (getI() = 0; getI() <= dimension; getI()++) {
		if (getI() = 1) {
			for (getJ() = 1; getJ() <= dimension; getJ()++) {
				cout << j;
			}
		}
		else {
			for (getJ() = getK() + 1; getJ() <= dimension; getJ()++) {
				cout << j;
			}
			for (getM() = 1; getM() <= dimension - getP(); getM()++) {
				cout << m;
			}

		}
		getK() -= 1;
		getP() += 1;
		cout << " ";
	}
}
//template class LatinSquare<int>;




