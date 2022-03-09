#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main()
{
    string linea; // para leer cada linea
    string texto;
    ifstream archivo("Prueba.txt");
    while (getline(archivo, linea)) {
        texto = texto + linea+"\n";
    }
    archivo.close();
    cout << texto << endl;
    //ofstream archivo2("Prueba.txt");
    //archivo2 << texto << "Nueva linea de texto"; //agregar mas lineas de texto
     
    
    
}

