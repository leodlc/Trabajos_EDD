/*
*   EjercicioExtra3_LDLC.cpp :
*  Hacer una clase con plantillas y que esta tenga una funcion pasarDato que devuelva el argumento
* cuando esta funcion es invocada
* Autor: Leonardo De La Cadena
*/ 


#include <iostream>
#include <stdlib.h>
#include <string>
#include "PasarDato.h"
using namespace std;


int main()
{
    string dato1;
    int dato2;
    float dato3;
    double dato4;

    cout << "Escriba una plabra u oracion" << endl;
    getline(cin, dato1);
    fflush(stdin);
    cout << "Escriba un numero de TIPO ENTERO" << endl;
    cin >> dato2;
    cout << "Escriba un numero de TIPO FLOTANTE" << endl;
    cin >> dato3;
    cout << "Escriba un numero de TIPO DOUBLE" << endl;
    cin >> dato4;

    PasarDato<string> despliegueString(dato1);
    despliegueString.pasarDato(dato1);
    PasarDato<int> despliegueInt(dato2);
    despliegueInt.pasarDato(dato2);
    PasarDato<float> despliegueFloat(dato3);
    despliegueFloat.pasarDato(dato3);
    PasarDato<double> despliegueDouble(dato4);
    despliegueDouble.pasarDato(dato4);


}
    


