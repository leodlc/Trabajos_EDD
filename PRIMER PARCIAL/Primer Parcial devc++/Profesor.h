/***********************************************************************
 * Module:  Profesor.h
 * Author:  AsrockLeo
 * Modified: lunes, 29 de noviembre de 2021 21:05:00
 * Purpose: Declaration of the class Profesor
 ***********************************************************************/

#if !defined(__Proyecto_Profesor_h)
#define __Proyecto_Profesor_h

#include <Persona.h>
#include <Asignatura.h>
#include <Alumno.h>

class Profesor : public Persona
{
public:
   Asignatura getAsignaturaImpartida(void);
   void setAsignaturaImpartida(Asignatura newAsignaturaImpartida);
   float getNotaAsignada(void);
   void setNotaAsignada(float newNotaAsignada);
   Profesor();
   ~Profesor();
   Alumno getAlumno(void);
   void setAlumno(Alumno newAlumno);
   void ingresarNotaP1(void);
   void ingresarNotaP2(void);
   void ingresarNotaP3(void);

protected:
private:
   Asignatura asignaturaImpartida;
   float notaAsignada;
   Alumno alumno;


};

#endif