#include <iostream>
#include <stdlib.h>
using namespace std;
class Persona {
	private://atributos
		int edad;
		string nombre;
	public://metodos
		Persona(int, string); //constructor
		void leer();
		void correr();

};
Persona::Persona(int _edad, string _nombre) {
	edad = _edad;
	nombre = _nombre;
}
void Persona::leer() {
	cout << "Soy " << nombre << " y estoy leyendo un libro" << endl;
}
void Persona::correr() {
	cout << "Soy " << nombre << " y estoy corriendo" << endl;
}
int main() {
	std::cout << "Hola mundo" << endl;
	Persona p1 = Persona(20, "Leonardo");
	Persona p2(19, "Maria");
	Persona p3(21,"Jutan");
	p2.correr();
	p1.leer();

	p3.leer();
	p3.correr();
	system("pause");
	return 0;
}
