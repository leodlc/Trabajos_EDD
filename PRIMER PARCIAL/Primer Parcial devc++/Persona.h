/***********************************************************************
 * Module:  Persona.h
 * Author:  AsrockLeo
 * Modified: lunes, 29 de noviembre de 2021 21:05:00
 * Purpose: Declaration of the class Persona
 ***********************************************************************/

#if !defined(__Proyecto_Persona_h)
#define __Proyecto_Persona_h

#include <Fecha.h>

class Persona
{
public:
   std::string getNombre(void);
   void setNombre(std::string newNombre);
   std::string getApellido(void);
   void setApellido(std::string newApellido);
   std::string getID(void);
   void setID(std::string newID);
   std::string getCedula(void);
   void setCedula(std::string newCedula);
   Fecha getFechaNacimiento(void);
   void setFechaNacimiento(Fecha newFechaNacimiento);
   std::string getCorreo(void);
   void setCorreo(std::string newCorreo);
   Persona();
   ~Persona();

protected:
private:
   std::string nombre;
   std::string apellido;
   std::string ID;
   std::string cedula;
   Fecha fechaNacimiento;
   std::string correo;


};

#endif