/***********************************************************************
 * Module:  Administrador.h
 * Author:  AsrockLeo
 * Modified: lunes, 29 de noviembre de 2021 21:05:00
 * Purpose: Declaration of the class Administrador
 ***********************************************************************/

#if !defined(__Proyecto_Administrador_h)
#define __Proyecto_Administrador_h

class Administrador
{
public:
   std::string getUsuario(void);
   void setUsuario(std::string newUsuario);
   std::string getContrasena(void);
   void setContrasena(std::string newContrasena);
   Administrador();
   ~Administrador();
   void registrarAlumno(void);
   void registroProfesor(void);

protected:
private:
   std::string usuario;
   std::string contrasena;


};

#endif