#include <iostream>
#include "Auto.h"
#include "Placa.h"
#include <string>
using namespace std;
int main()
{
    Auto car;
    
    string placa;
    string provincia;
    Placa generar;
    cout << "Ingrese la provincia" << endl;
    getline(cin, provincia);
    //generar.asignarPlaca(placa);
    //cout<<generar.asignarPlaca(placa)<<endl;
    //provincia=car.getPlaca();
    cout<<generar.asignarPlaca(provincia)<<endl;

    //cout << provincia << endl;


    
    
    
    
}

