/*
*   Se le da una función main () que toma un conjunto de entradas. El tipo de entrada gobierna el tipo 
    de operación a realizar, es decir, la concatenación de cadenas y la suma de int o float .
    Debe escribir la plantilla de clase AddElements que tiene una función add () para dar la 
    suma de los elementos int o float . También necesita escribir una especialización de plantilla 
    para el tipo de cadena con una función concatenar () para concatenar la segunda cadena a la primera 
    cadena.
    Autor: Leonardo De La Cadena
*/

#include <iostream>
#include <stdio.h>
#include <string>
#include "AddElementos.h"
//#include "Oracion.h"
//#include "AddElementos.cpp"

using namespace std;

int main()
{
    int nLineas;
    float numero1, numero2;
    string cadena1, cadena2;
    cout << " Escriba dos numeros: "<<endl;
    cin >> numero1, numero2;
    AddElementos<float> add(numero1,numero2);
    cout << "Suma de los numeros ingresados: " << add.addNumeros() << endl;
    /*
	cout << "Ingrese el numero de lineas: "; cin >> nLineas;

    for (int i = 0; i <= nLineas; i++) {
        cout << "Linea " << i << " Escriba dos numeros: "<<endl;
        cin >> numero1, numero2;
        AddElementos<float> add(numero1,numero2);
        cout << "Suma de los numeros ingresados: " << add.addNumeros() << endl;
    }
    */
    return 0;

}


