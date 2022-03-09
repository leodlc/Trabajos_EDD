
#if !defined(__OchoReinas2_Reina_h)
#define __OchoReinas2_Reina_h
#include <iostream>
#include <fstream> 

using namespace std;

class Reina
{
public:
   Reina(int n1);
   ~Reina();
   void solucion(int x, int y, int n1);
   void bloquear(int x, int y);
   void quitarRelleno(int x, int y);
   void mostrar();
   void solucionReinas();

protected:
private:
   bool** validar;
   char** tablero;
   fstream enter;
   int contador;
   int n;


};

#endif
