#include <iostream>
using namespace std;
template <typename T>
class Caja {
public:
	Caja();
	Caja(T);
	Caja(T, T);
	Caja(T, T, T);
	void setAncho(T ancho);
	void setAlto(T alto);
	void setProfundidad(T profundidad);
	T getAncho();
	T getAlto();
	T getProfundidad();
	void mostrarMedidas();
private:
	T ancho;
	T alto;
	T profundidad;
};
template <typename T>
Caja<T>::Caja() {
	this->ancho = 1;
	this->alto = 1;
	this->profundidad = 1;
}
template <typename T>
Caja<T>::Caja(T _alto) {
	this->alto = _alto;
	this->ancho = 1;
	this->profundidad = 1;
}
template <typename T>
Caja<T>::Caja(T _alto, T _ancho) {
	this->alto = _alto;
	this->ancho = _ancho;
	this->profundidad = 1;
}
template <typename T>
Caja<T>::Caja(T _alto, T _ancho, T _profundidad) {
	this->alto = _alto;
	this->ancho = _ancho;
	this->profundidad = _profundidad;
}
template <typename T>
void Caja<T>::mostrarMedidas() {
	cout << "\nValor del atributo Alto " << getAlto() << endl;
	cout << "\nValor del atributo Ancho " << getAncho() << endl;
	cout << "\nValor del atributo Profundidad " << getProfundidad() << endl;
}
template <typename T>
void Caja<T>::setAlto(T _alto) {
	this->alto = _alto;
}
template <typename T>
void Caja<T>::setAncho(T _ancho) {
	this->ancho = _ancho;
}
template <typename T>
void Caja<T>::setProfundidad(T _profundidad) {
	this->profundidad = _profundidad;
}

template <typename T>
T Caja<T>::getAlto() {
	
	return this->alto;
}

template <typename T>
T Caja<T>::getAncho() {
	
	return this->ancho;
}
template <typename T>
T Caja<T>::getProfundidad() {
	
	return this->profundidad;
}

int main(int argc, char** argv) {
	const int tam = 5;
	Caja<int> cajas[tam];
	int i = 0;
	for (int i = 0; i < tam; i++) {
		Caja<int> caja(i + 1, i + 1, i + 1);
		cajas[i] = caja;
	}
	i = 1;
	for (auto Caja : cajas) {
		cout << " ";
		cout << "Caja " << i << " del arreglo estatico";
		
		Caja.mostrarMedidas();
		i++;
	}
	return 0;
	/*Caja<int> caja1;
	Caja<int> caja2(3, 5);
	Caja<float> caja3(3.3f, 5.5f, 8.8f);*/
	/*cout << "\n";
	cout << "Caja 1: ";
	caja1.mostrarMedidas();
	cout << "\n";
	cout << "Caja 2: ";
	caja2.mostrarMedidas();
	cout << "\n";
	cout << "Caja 3: ";
	caja3.mostrarMedidas();
	return 0;*/
}