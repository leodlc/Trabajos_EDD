
#include <iostream>
#include <fstream>  
#include "Reina.h"
#include "Ingreso.h"

using namespace std;

int main(int argc, char** argv) {
	int n;
	cout<<"\tCuantas reinas: "<<endl;
	cin>>n;
	Reina *obj= new Reina(n);
	obj->solucionReinas();
	cout<<obj->solucionReinas();<<endl;
	cout<<"Se creo el archivo solucion.txt"<<endl;

	return 0;
}

