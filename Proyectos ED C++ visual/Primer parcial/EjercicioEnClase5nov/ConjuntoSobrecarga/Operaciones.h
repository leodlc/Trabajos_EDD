#pragma once
#include "Conjunto.h"
template <class T>
void interseccion(Conjunto<T> elementosA, Conjunto<T> elementosB) {
    int arreglo1[4] = elementosA.getElementos();
    int arreglo2[4] = elementosB.getElementos();

    int x, y;
    for (x = 0; x < 4; x++) {
        for (y = 0; y < 4; y++) {
            if (arreglo1[x] == arreglo2[y]) {
                cout << arreglo1[x] << " , ";
                y = 4;
            }
        }
    }
}
