/***********************************************************************
 * Module:  Fecha.h
 * Author:  AsrockLeo
 * Modified: miércoles, 1 de diciembre de 2021 7:54:36
 * Purpose: Declaration of the class Fecha
 ***********************************************************************/

#if !defined(__fecha_pruebaConjunta2_Fecha_h)
#define __fecha_pruebaConjunta2_Fecha_h

class Fecha
{
public:
   Fecha();
   ~Fecha();
   int getDia(void);
   void setDia(int newDia);
   int getMes(void);
   void setMes(int newMes);
   int getAnio(void);
   void setAnio(int newAnio);
   int calcularEdad(void);

protected:
private:
   int dia;
   int mes;
   int anio;


};

#endif