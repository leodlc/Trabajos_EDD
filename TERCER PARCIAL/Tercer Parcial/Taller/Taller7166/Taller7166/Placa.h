#include <stdio.h> 
#include <string.h>
#include <stdlib.h> 
#include <math.h> 
#include <time.h> 
#include <iostream> 
using namespace std; 

class Placa
{
private:
    enum { A, B, U, C, X, H, O, E, W, G, I, L, R, M, V, N, S, P, K, Q, T, Z, Y };

public:
    string asignarPlaca(string);
};


string Placa::asignarPlaca(string provincia) { 

    
    string texto=" ";
    if(provincia=="AZUAY"){
    texto="A";                
    }if(provincia=="CAÑAR"){
    texto="U";                    
    }if(provincia=="CARCHI"){
    texto="C";                    
    }if(provincia=="CAÑAR"){
    texto="X";                    
    }if(provincia=="CHIMBORAZO"){
    texto="H";                          
    }if(provincia=="ELORO"){
    texto="O";
    }if(provincia=="ESMERALDAS"){
    texto="E";
    }if(provincia=="GALAPAGOS"){
    texto="W";
    }if(provincia=="GUAYAS"){
    texto="G";
    }if(provincia=="IMBABURA"){
    texto="I";
    }if(provincia=="LOJA"){
    texto="L";
    }if(provincia=="LOSRIOS"){
    texto="R";
    }if(provincia=="MANABI"){
    texto="M";
    }if(provincia=="MORONASANTIAGO"){
    texto="V";
    }if(provincia=="NAPO"){
    texto="N";
    }if(provincia=="PASTAZA"){
    texto="S";
    }if(provincia=="PICHINCHA"){
    texto="P";
    }if(provincia=="SUCUMBIOS"){
    texto="K";
    }if(provincia=="ORELLANA"){
    texto="Q";
    }if(provincia=="TUNGURAHUA"){
    texto="T";
    }if(provincia=="ZAMORACHINCHIPE"){
    texto="Z";
    }if(provincia=="SANTAELENA"){
    texto="Y";
    }if(provincia=="BOLIVAR"){
    texto="B";
	}
    
    char nmatricula[7]; 
    cout<<"a"<<endl; 
    string numeros="0123456789"; 
    string letrasma="BCFGHJKLMNPRSTVWXYZ"; 

    /* alteramos la secuencia de azar */ 
    srand ( time(NULL) ); 

     nmatricula[0]= texto[0];
    for(int i=0;i<=4;i++) //generamos los 4 numeros 
    { 
    nmatricula[i]=letrasma[rand()%20]; 

    } 
   
    for(int i=4;i<=5;i++) //generamos las 3 letras 
    { 
    nmatricula[i]=numeros[rand()%10]; 
    cout<<"c"<<endl; 
    } 
    string placa;
    placa.assign(nmatricula, 7);

    return placa;


} 

