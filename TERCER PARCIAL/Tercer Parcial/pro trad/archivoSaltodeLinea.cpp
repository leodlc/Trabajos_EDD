#include <iostream>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;
using namespace std;
int main()
{
	
	string primeraL;
	string segundaL;
	ofstream file; // out file stream
	file.open("prueba.txt");
	cout<<"Ingrese nombre: "<<endl;
	getline(cin,primeraL);
	fflush(stdin);
	cout<<"Ingrese apellido: "<<endl;
	getline(cin,segundaL);
	fflush(stdin);
	file << primeraL << endl << segundaL;
	file.close();
	
	
	ifstream filer;
	string line;
	cout<<"Lectura de archivo"<<endl;
	filer.open("prueba.txt");
	while (getline(filer, line)) {
    	cout << line << endl;
	}	
	filer.close();




	
	
	return 0 ;
 }