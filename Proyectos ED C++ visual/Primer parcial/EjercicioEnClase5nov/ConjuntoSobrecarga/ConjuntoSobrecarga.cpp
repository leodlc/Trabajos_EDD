#include <iostream>
#include "Conjunto.h"
#include "Operaciones.h"
using namespace std;

int main()
{
    /*int tamanioConjunto=0;
    
    cout << "Ingrese el el tamanio de los conjuntos" << endl;
    cin >> tamanioConjunto;
    int valor1[100];
    int valor2[100];
    cout << "Conjunto 1:" << endl;
    for (int i = 0; i < tamanioConjunto; i++) {
        cout << "Ingrese el valor" << i + 1 << endl;
        cin >> valor1[i];
    }
    cout << "Conjunto 2:" << endl;
    for (int i = 0; i < tamanioConjunto; i++) {
        cout << "Ingrese el valor" << i + 1 << endl;
        cin >> valor2[i];
    }*/
    int valor1, valor2, valor3, valor4;
    int valor1Conj2, valor2Conj2, valor3Conj2, valor4Conj2;
    cout << "CONJUNTO 1:" << endl;
    cout << "Ingrese el valor 1" << endl;
    cin >> valor1;
    cout << "Ingrese el valor 2" << endl;
    cin >> valor2;
    cout << "Ingrese el valor 3" << endl;
    cin >> valor3;
    cout << "Ingrese el valor 4" << endl;
    cin >> valor4;
    cout << "CONJUNTO 2:" << endl;
    cout << "Ingrese el valor 1" << endl;
    cin >> valor1Conj2;
    cout << "Ingrese el valor 2" << endl;
    cin >> valor2Conj2;
    cout << "Ingrese el valor 3" << endl;
    cin >> valor3Conj2;
    cout << "Ingrese el valor 4" << endl;
    cin >> valor4Conj2;
   

    
    
    int elementosA[4] = { valor1,valor2,valor3,valor4 };
    int elementosB[4] = { valor1Conj2,valor2Conj2,valor3Conj2,valor4Conj2 };
    int x = 0, y = 0;
    Conjunto<int> conjuntoA(elementosA), conjuntoB(elementosB);
    interseccion(conjuntoA, conjuntoB);
    //Conjunto<int> C;
    /*for (x = 0; x < 4; x++) {
        for (y = 0; y < 4; y++) {
            if (elementosA[x]==elementosB[y]) {
                cout << elementosA[x] << " , " ;
                y = 4;
            }
        }
    }*/
    system("Pause");
    return 0;

}

