// impresionNumeros.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
using namespace std;
int imprimirNum(int);
int imprimirNum(int i=0) {
    for ( i ; i < 10; i++) {
        cout << i + 1 << endl;
        
    }
    return i;
    
}
int main()
{
    int num=0;
    imprimirNum(num);
    return 0;
}

