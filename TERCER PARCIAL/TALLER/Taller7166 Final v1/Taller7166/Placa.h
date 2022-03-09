#include <stdio.h> 
#include <string.h>
#include <string>
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
    Tools tool;
    
    char nmatricula[7]; 

    string numeros="0123456789"; 
    string letrasma="BCFGHJKLMNPRSTVWXYZ"; 
    string cero = "0";

    char* nums = new char[3];
    char* lets = new char[2];

    string num1;
    string num2;
    string num3;

    /* alteramos la secuencia de azar */ 

     nmatricula[0]= texto[0];
    
     if (tool.compare(provincia, "AZUAY") == 0) {
         texto = "A";
         srand(time(NULL));
         
         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("A" + placaLets + cero + num1 + num2 + num3);

     }if (tool.compare(provincia, "CAÑAR") == 0) {
         texto = "U";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("U" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "CARCHI") == 0) {
         texto = "C";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("C" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "COTOPAXI") == 0) {
         texto = "X";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("X" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "CHIMBORAZO") == 0) {
         texto = "H";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("H" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "ELORO") == 0) {
         texto = "O";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("O" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "ESMERALDAS") == 0) {
         texto = "E";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("E" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "GALAPAGOS") == 0) {
         texto = "W";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("W" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "GUAYAS") == 0) {
         texto = "G";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("G" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "IMBABURA") == 0) {
         texto = "I";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("I" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "LOJA") == 0) {
         texto = "L";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("L" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "LOSRIOS") == 0) {
         texto = "R";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("R" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "MANABI") == 0) {
         texto = "M";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("M" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "MORONASANTIAGO") == 0) {
         texto = "V";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("V" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "NAPO") == 0) {
         texto = "N";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("N" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "PASTAZA") == 0) {
         texto = "S";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("S" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "PICHINCHA") == 0) {
         texto = "P";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("P" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "SUCUMBIOS") == 0) {
         texto = "K";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("K" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "ORELLANA") == 0) {
         texto = "Q";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("Q" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "TUNGURAHUA") == 0) {
         texto = "T";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("T" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "ZAMORACHINCHIPE") == 0) {
         texto = "Z";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("Z" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "SANTAELENA") == 0) {
         texto = "Y";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("Y" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "BOLIVAR") == 0) {
         texto = "B";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("B" + placaLets + cero + num1 + num2 + num3);
     }if (tool.compare(provincia, "STODOMINGO") == 0) {
         texto = "B";
         srand(time(NULL));

         for (int i = 0; i <= 1; i++) //generamos las 3 letras 
         {
             lets[i] = letrasma[rand() % 20];

         }

         for (int i = 2; i <= 2; i++) //generamos las 4 numeros
         {
             srand(time(NULL));
             num1 = to_string((rand() % 10));
             num2 = to_string((rand() % 10));
             num3 = to_string((rand() % 10));
         }
         string placaNums, placaLets;

         placaNums.assign(nums, 3);
         placaLets.assign(lets, 2);

         return ("B" + placaLets + cero + num1 + num2 + num3);
     }
} 

