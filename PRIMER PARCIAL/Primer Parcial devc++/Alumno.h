/***********************************************************************
 * Module:  Alumno.h
 * Author:  AsrockLeo
 * Modified: lunes, 29 de noviembre de 2021 21:05:00
 * Purpose: Declaration of the class Alumno
 ***********************************************************************/

#if !defined(__Proyecto_Alumno_h)
#define __Proyecto_Alumno_h

#include <Persona.h>
#include <Asignatura.h>

class Alumno : public Persona
{
public:
   Asignatura getListaAsignatura(void);
   void setListaAsignatura(Asignatura newListaAsignatura);
   float getNotaAdquirida(void);
   void setNotaAdquirida(float newNotaAdquirida);
   Alumno();
   ~Alumno();
   void verNotas(void);

protected:
private:
   Asignatura* listaAsignatura;
   float notaAdquirida;


};

#endif