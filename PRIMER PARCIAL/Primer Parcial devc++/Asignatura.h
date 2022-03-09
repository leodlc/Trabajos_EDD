/***********************************************************************
 * Module:  Asignatura.h
 * Author:  AsrockLeo
 * Modified: lunes, 29 de noviembre de 2021 21:05:00
 * Purpose: Declaration of the class Asignatura
 ***********************************************************************/

#if !defined(__Proyecto_Asignatura_h)
#define __Proyecto_Asignatura_h

class Alumno;
class Profesor;

class Asignatura
{
public:
   std::string getNombreAsignatura(void);
   void setNombreAsignatura(std::string newNombreAsignatura);
   std::string getProfesorAsignado(void);
   void setProfesorAsignado(std::string newProfesorAsignado);
   std::string getNRC(void);
   void setNRC(std::string newNRC);
   Asignatura();
   ~Asignatura();
   float calcularNotaFinal(void);
   bool aprobacion(void);

   Alumno** alumno;
   Profesor** profesor;

protected:
private:
   std::string nombreAsignatura;
   std::string profesorAsignado;
   std::string NRC;
   float* calificacion;
   float notaFinal;


};

#endif