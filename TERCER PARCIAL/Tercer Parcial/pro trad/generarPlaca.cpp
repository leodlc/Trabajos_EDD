#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <iostream>
#include <stdio.h>
using namespace std;


typedef struct{ //definimos la estructura
	string matricula;
}coche;

void generarmatricula (string &matricula);
void mayuscula (string &s);
bool validamatriculas(string &matricula);

int main() {

	coche coches;
	coche cincoche[50];
	int opcion,x;
	bool estado;

	do{
		do{
			cout<<"1. Genera matricula aleatorias"<<endl;
			cout<<"2. Genera 50 matriculas aleatorias"<<endl;
			cout<<"3. Mete matricula por teclado y validala"<<endl;
			cout<<"0. Salir del programa"<<endl;
			cin>>opcion;
		}
		while(opcion<0|| opcion>3);
		switch(opcion){
		case 1:

			cout<<"generamos una matricula aleatoria"<<endl;

			generarmatricula(coches.matricula);

			cout<<coches.matricula<<endl;


			break;
		case 2:

			cout<<"generamos cincuenta matriculas aleatorias"<<endl;

						for(x=0;x<50;x++){
							generarmatricula(cincoche[x].matricula);
						}

						for(x=0;x<50;x++){
							cout<<cincoche[x].matricula<<endl;
						}

			break;

		case 3:

				do{
			cout << "Introduce la matricula por teclado: ";
							 cin >> coches.matricula;

							 mayuscula(coches.matricula);

								cout<<coches.matricula<<endl;

							 estado=validamatriculas(coches.matricula);
							if(estado==true){
								cout<<"La matricula introducida es valida y se ha guardado correctamente"<<endl;
							}
							else{
								cout<<"Introduzca una matricula valida"<<endl;
							}
			}while(estado==false);


			break;
		}
	}
	while(opcion!=3);

	return 0;
}

void generarmatricula (string &matricula){
	char nmatricula[7];
	string numeros="0123456789";
	string letrasma="BCFGHJKLMNPRSTVWXYZ";

	for(int i=0;i<2;i++) //generamos las 3 letras     //int i=0;i<4;i++
	{
		nmatricula[i]=letrasma[rand()%letrasma.length()];
	}
	
	for(int i=2;i<6;i++) //generamos los 4 numeros   //int i=4;i<7;i++
	{
		nmatricula[i]=numeros[rand()%numeros.length()];
	}
	
	nmatricula[6] = '\0';

	matricula = string(nmatricula); //lo pasamos a string para que sea mas facil su manejo

	
}

void mayuscula (string &s){

	 /*for(int i;i<s.length;i++){ //esto funcionaria si el string solo fueran caracteres
		 s[i]=toupper(s[i]);

	 }*/
	 for(int i=4;i<7;i++){ //solo pasamos a mayuscula los caracteres
		 s[i]=toupper(s[i]);

	 }


}

bool validamatriculas(string &matricula){

	string numeros="0123456789";
	string letrasma="BCFGHJKLMNPRSTVWXYZ";
	bool valida=true;
	if (matricula.length()==7){ //revisamos que sea si o si de 7 caracteres

		for(int i=0;i<4;i++){ //validamos los cuatro numeros
			if(numeros.find(matricula[i])>numeros.length())
				valida=false;
		}

		for(int i=4;i<7;i++){ //validamos los tres caracteres
			if (letrasma.find(matricula[i])>letrasma.length())
								valida=false;
		}
	}else
		valida=false;

	return valida;
}
	