/**************************************************************************
*		UNIVERSIDAD DE LAS FUERZAS ARMADAS ESPE
*TITULO: EXPOSICION - SHELLSORT
*AUTOR(ES): LUIS CUEVA, CHRISTIAN ANDRANGO, ARIEL JARA. JORGE PAUCAR, JORGE AGUAS, CRISTOFER ZAMBRANO
*FECHA: MIERCOLES 22 DE DICIEMBRE DE 2021
*VERSION: 1
*ESTRUCTURA DE DATOS
*NRC: 7166
***************************************************************************/
#include <iostream>
#include <stdio.h>
#include <windows.h>
#include "Shellsort.h"
using namespace std;

int main()
{
    bool a = true;
    int n = 0, m=0;
    do {
        printf("\nCuantos numeros desea ingresar: ");
        scanf_s("%d", &n);
        while (n < 1 || n>100) {
            printf("Ingreso solo numeros del 1 al 100:");
            scanf_s("%d", &n);
        }

        for (int i = 0; i < n; i++) {
            cout << endl << "Dato[" << i + 1 << "]: "; cin >> Shellsort::vector[i];
        }

        printf("\n///////////////////////////////////////////\n");
        printf("vector original\n");
        for (int i = 0; i < n; i++) {
            cout << Shellsort::vector[i] << " ";
        }

        Shellsort::shellsort(Shellsort::vector, n);
        printf("\nVector Ordenado Con Metodo de ShellSort :\n");
        for (int i = 0; i < n; i++) {
            cout << Shellsort::vector[i] << " ";
        }
        printf("\n");
        system("pause");

        printf("\nDesea continuar? ");
        printf("\n1. Si");
        printf("\n2. No");
        scanf_s("%d", &m);
        while (m < 1 || m>2) {
            printf("Ingreso solo numeros del 1 al 2:");
            scanf_s("%d", &m);
        }
        if (m == 2) {
            a = false;
        }

    } while (a == true);
}


