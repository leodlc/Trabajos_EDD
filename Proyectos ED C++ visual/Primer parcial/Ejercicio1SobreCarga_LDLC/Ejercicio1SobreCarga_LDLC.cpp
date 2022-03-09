/** UNIVERSIDAD DE LAS FUERZAS ARMADAS "ESPE"
*			INGENIERIA SOFTWARE
*
*AUTOR: Leonardo de la Cadena

*TEMA: CREACION DE UN PROGRAMA CON METODOS SOBRECARGADOS<>
*FECHA DE CREACION : 05 DE NOVIEMBRE DEL 2021
*FECHA DE MODIFICACION: 06 DE NOVIEMBRE DE 2021
* DESCRIPCION DEL PROGRAMA: Programa en el que se ingresan puntajes de alumno y calcula 
* su nota final con metodos sobrecargados
* */
#include <iostream>
#include "Puntaje.h"
using namespace std;

int main()
{
    double practica, teorica, participacion, notaFinal = 0;
    
    
    cout << "Dige la nota practica: " << endl;
    cin >> practica;
    cout << "Dige la nota teorica: " << endl;
    cin >> teorica;
    cout << "Dige la nota de participacion: " << endl;
    cin >> participacion;
    Puntaje<double> nota(practica, teorica, participacion, notaFinal);
    
    notaFinal = nota.calcNotaPractica() + nota.calcNotaTeorica() + nota.calcNotaParticipacion();
    cout << "La nota final del alumno es: " << notaFinal << endl;
    cin.ignore();
    system("pause");
    return 0;
}

